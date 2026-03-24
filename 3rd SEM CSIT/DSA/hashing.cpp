#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

// Initialize table
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    cout << "---Hash table initialized.---" << endl;
}

// Display hash table
void display() {
    cout << "\nIndex\tValue\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";
        if (hashTable[i] != -1)
            cout << hashTable[i];
        else
            cout << "Empty";
        cout << endl;
    }
}

// Linear Probing
void linearProbing(int key) {
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            cout << "Hash table is full!" << endl;
            return;
        }
    }

    hashTable[(index + i) % SIZE] = key;
    cout << key << " inserted using Linear Probing." << endl;
}

// Quadratic Probing
void quadraticProbing(int key) {
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i * i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            cout << "Hash table is full!" << endl;
            return;
        }
    }

    hashTable[(index + i * i) % SIZE] = key;
    cout << key << " Inserted using Quadratic Probing." << endl;
}

// Second hash function for Double Hashing
int hash2(int key) {
    int step = 7 - (key % 7);
    if (step == 0) // safety check
        step = 1;
    return step;
}

// Double Hashing
void doubleHashing(int key) {
    int index = key % SIZE;
    int step = hash2(key);
    int i = 0;

    while (hashTable[(index + i * step) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            cout << "Hash table is full!" << endl;
            return;
        }
    }

    hashTable[(index + i * step) % SIZE] = key;
    cout << key << " Inserted using Double Hashing." << endl;
}

int main() {
    int choice, key;
    initialize();

    do {
        cout << "\n===== HASHING MENU =====" << endl;
        cout<<"----Swornim Maharjan----"<<endl;
        cout << "1. Insert using Linear Probing" << endl;
        cout << "2. Insert using Quadratic Probing" << endl;
        cout << "3. Insert using Double Hashing" << endl;
        cout << "4. Display Hash Table" << endl;
        cout << "5. Initialize (Clear Table)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            linearProbing(key);
            break;

        case 2:
            cout << "Enter key to insert: ";
            cin >> key;
            quadraticProbing(key);
            break;

        case 3:
            cout << "Enter key to insert: ";
            cin >> key;
            doubleHashing(key);
            break;

        case 4:
            display();
            break;

        case 5:
            initialize();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}

