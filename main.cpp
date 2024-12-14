#include "list.h"
#include <iostream>

using namespace std;

int main() {
    TrainList trainList;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Train\n";
        cout << "2. Delete Train\n";
        cout << "3. Edit Trains\n";
        cout << "4. Print All Trains\n";
        cout << "5. Sort Trains by number\n";
        cout << "6. Search Trains by number\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";;

        cin >> choice;
        switch (choice) {
                case 1: {
                    string destination, time;
                    int number, index;
                    cout << "Destination: ";
                    getline(cin >> ws, destination);
                    cout << "Number of Train: ";
                    cin >> number;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Time of Departure: ";
                    getline(cin, time);
                    cout << "Enter index of train: ";
                    cin >> index;
                    TRAIN* new_train = new TRAIN(destination, number, time);
                    try {
                        trainList.addTrain(new_train, index - 1);
                        cout << "Added." << endl;
                    } catch (const out_of_range& e) {
                        cout << e.what() << endl;
                        delete new_train;
                    }
                    break;
            }
            case 2: {
                int index;
                cout << "Enter index of the train: ";
                cin >> index;
                try {
                    trainList.delete_train(index - 1);
                    cout << "Deleted." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Enter index of the train: ";
                cin >> index;
                try {
                    trainList.edit(index - 1);
                    cout << "Edited." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                trainList.printAll();
                break;
            }
            case 5: {
                trainList.sortByNumber();
                cout << "Successfully sorted." << endl;
                trainList.printAll();
                break;
            }
            case 6: {
                cout << "Enter the train number to search for: ";
                int number;
                cin >> number;
                trainList.printTrainsToNumber(number);
                break;
            }
            case 0: {
                cout << "Exiting...\n" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n" << endl;
                break;
            }    
        }
    } while (choice != 0);

    return 0;
}