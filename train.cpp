#include "Train.h"

TRAIN::TRAIN() : destination(""), number(0), time("00:00") {}

TRAIN::TRAIN(string destination, int number, string time)
    : destination(destination), number(number), time(time) {}

string TRAIN::getDestination() {
    return this->destination;
}

void TRAIN::setDestination(const string& d) {
    this->destination = d;
}

int TRAIN::getNumber() {
    return this->number;
}

void TRAIN::setNumber(const int& n) {
    this->number = n;
}

string TRAIN::gettime() {
    return this->time;
}

void TRAIN::settime(const string& t) {
    this->time = t;
}

void TRAIN::print() {
    cout << "Destination: " << this->getDestination() << endl;
    cout << "Number: " << this->getNumber() << endl;
    cout << "Time of Department: " << this->gettime() << endl; 
    cout << endl;
}

void TRAIN::edit() {
    int choice;
    cout << "Change:\n";
    cout << "1. Destination\n";
    cout << "2. Number\n";
    cout << "3. Time of Department\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            string new_destination;
            cout << "Enter new Destination: ";
            cin.ignore();
            getline(cin, new_destination);
            setDestination(new_destination);
            break;
        }
        case 2: {
            int new_number;
            cout << "Enter new Number: ";
            cin >> new_number;
            setNumber(new_number);
            break;
        }
        case 3: {
            string new_time;
            cout << "Enter new Timfe of department: ";
            cin.ignore();
            getline(cin, new_time);
            settime(new_time);
            break;
        }
        default:
            cout << "Ivalid!" << endl;
    }
}