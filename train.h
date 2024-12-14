#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TRAIN {
private:
    string destination;
    int number;
    string time; 

public:
    TRAIN();
    TRAIN(string destination, int number, string time);

    string getDestination();
    void setDestination(const string &destination);
    int getNumber();
    void setNumber(const int &number);
    string gettime();
    void settime(const string &timer);
    void print();
    void edit();
    friend ostream& operator<<(ostream& os, const TRAIN& train);
    friend istream& operator>>(istream& is, TRAIN& train);
};

#endif