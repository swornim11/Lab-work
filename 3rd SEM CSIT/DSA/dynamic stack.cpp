#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << "Pushed: " << value << endl;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped: " << temp->data << endl;

        top = top->next;
        delete temp;
    }

    // Display stack
    void display() {
        if (top == NULL) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;
    cout << "=====Swornim Maharjan=====\n";
    cout << "===Stack using linked list===\n";
    do {
        cout << "\n--- Dynamic Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

