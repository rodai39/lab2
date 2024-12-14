#include "second.h"
#include "iostream"
int main() {
    try {
        int wordCount;
        cout << "Enter amount of words in sentence: ";
        if (!(cin >> wordCount)) {
            throw invalid_argument("Incorrect input of the number of words.");
        }
        int choice;
        cout << "Line or File?\n1 - Line\n2 - File\n";
        if (!(cin >> choice)) {
            throw invalid_argument("Incorrect input of the source selection.");
        }
        if (choice == 1) {
            cin.ignore();
            char text[8192];
            cout << "Enter text: ";
            cin.getline(text, sizeof(text));
            if (cin.fail()) {
                throw overflow_error("Out of range.");
            }
            Filter filter(text, wordCount, true);
            filter.result();
        } else if (choice == 2) {
            char filename[256];
            cout << "Enter file's name: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("The file was not found or could not be opened.");
            }
            file.close();
            Filter filter(filename, wordCount);
            filter.result();
        } else {
            throw out_of_range("A non-existent source has been selected");
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const overflow_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 2;
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 3;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
        return 4;
    }
    catch (...) {
        cerr << " Error." << endl;
        return -1;
    }
    return 0;
}

