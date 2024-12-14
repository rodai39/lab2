#include "list.h"
#include <algorithm>


TrainList::TrainList() : head(nullptr), tail(nullptr), count(0) {
    cout << "The constructor is called without parameters for the TrainList class\n";
}

TrainList::TrainList(Node* h, Node* t, const int c) : head(h), tail(t), count(c) {
    cout << "The constructor is called with parameters for the TrainList class\n";
}

TrainList::TrainList(const TrainList& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "The copy constructor for the TrainList class is called\n\n";
}

TrainList::~TrainList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    count = 0;
    cout << "The destructor for the TrainList class is called\n" << endl;
}

Node* TrainList::get_head() {
    return this->head;
}

Node* TrainList::get_tail() {
    return this->tail;
}

void TrainList::addTrain(TRAIN* Tr, int index) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    
    Node* node_to_add = new Node;
    node_to_add->data = Tr;
    node_to_add->next = nullptr;

    if (index == 0) {
        node_to_add->next = head;
        head = node_to_add;
        if (count == 0) {
            tail = node_to_add;
        }
    } else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        node_to_add->next = prev->next;
        prev->next = node_to_add;
        
        if (node_to_add->next == nullptr) {
            tail = node_to_add;
        }
    }
    ++count;
}

TrainList& TrainList::edit(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    temp->data->edit();
    return *this;
}

TrainList& TrainList::delete_train(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp->data;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp->data;
        delete temp;
    }

    --count;
    return *this;
}


void TrainList::printAll() const {
    Node* temp = head;
    if (count == 0) {
        cout << "No trains available.\n";
        return;
    }

    int index = 1;
    while (temp != 0) {
        cout << index << " - Info:\n";
        temp->data->print();
        temp = temp->next;
        index++;
    }
}

void TrainList::sortByNumber() {
    if (count < 2) return;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data->getNumber() > j->next->data->getNumber()) {
                TRAIN* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void TrainList::printTrainsToNumber(const int number) {

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data->getNumber() == number) {
            temp->data->print();
            return;
        }
        temp = temp->next;
    }
    cout << "Train " << number << " not found." << endl;
}

TrainList& TrainList::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    return *this;
}