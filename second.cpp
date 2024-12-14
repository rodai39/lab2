#include "second.h"
Filter::Filter() : source(""), count(0), isTextSource(false)
{
    cout << "The constructor is called without parameters for the Filter class\n";
}
Filter::Filter(const string& filename, int count) : source(filename), count(count), isTextSource(false) {
    cout << "The constructor is called with parameters for the Filter class\n";
}
Filter::Filter(const string& text, int count, bool isText) : source(text), count(count), isTextSource(isText) {
    cout << "The constructor is called with parameters for the Filter class\n";
}
Filter::Filter(const Filter& other) : source(other.source), count(other.count), isTextSource(other.isTextSource) {
    cout << "The copy constructor for the Filter class is called\n";
}
Filter::~Filter() {
    cout << "The destructor for the Filter class is called\n";
}
void Filter::result() const {
    string text;

    if (isTextSource) {
        text = source;
    } 
    else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "Error: " << source << endl;
            return;
        }
        ostringstream buffer;
        buffer << file.rdbuf();
        text = buffer.str();
        file.close();
    }
    cout << "Text:\n" << text << "\n\n";
    string* sentences = nullptr;
    int sentenceCount = 0;
    split(text, sentences, sentenceCount);
    cout << "Amount of sentences: " << sentenceCount << endl;
    for (int i = 0; i < sentenceCount; ++i) 
    {
        int words = count_words(sentences[i]);
        if (words == count) {
            cout << sentences[i] << endl;
        }
    }
    delete[] sentences;
}
void Filter::split(const string& text, string*& sentences,
int& sentenceCount) const {
    const int maxSentences = 100;
    sentences = new string[maxSentences];
    sentenceCount = 0;
    ostringstream sentenceStream;
    for (char ch : text) {
        sentenceStream << ch;
        if (ch == '.' || ch == '!' || ch == '?') {
            if (sentenceCount < maxSentences) {
                sentences[sentenceCount++] = sentenceStream.str();
                sentenceStream.str("");
                sentenceStream.clear();
            }
        }
    }
    if (!sentenceStream.str().empty() && sentenceCount < maxSentences) {
        sentences[sentenceCount++] = sentenceStream.str();
    }
}
int Filter::count_words(const string& sentence) const {
    int count = 0;
    istringstream ss(sentence);
    string word;
    while (ss >> word) {
    ++count;
    }
    return count;
}
