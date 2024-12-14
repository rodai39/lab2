#ifndef TRAINLIST_H
#define TRAINLIST_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "train.h"

struct Node
{
    Node* next;
    TRAIN* data;
};

class TrainList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    TrainList();
    TrainList(Node* head, Node* tail, const int counter);
    TrainList(const TrainList& other);
    ~TrainList();

    Node* get_head();
    Node* get_tail();

    void addTrain(TRAIN* Tr, int index);
    TrainList& delete_train(int index);
    TrainList& edit(int index);
    void printAll() const;
    void printTrainsToNumber(const int number);
    void sortByNumber();
    TrainList& operator[](int index);
};

#endif