#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
class Filter {
    private:
    string source;
    int count;
    bool isTextSource;
    void split(const string& text, string*& sentences, int&sentenceCount) const;
    int count_words(const string& sentence) const;
    public:
    Filter();
    Filter(const string& filename, int wordCount);
    Filter(const string& text, int wordCount, bool isText);
    Filter(const Filter& other);
    ~Filter();
    void result() const;
};
