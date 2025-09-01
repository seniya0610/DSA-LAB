// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class linkedlist {
    Node* head;

public:
    linkedlist() {
        head = NULL;
    }

    void Append(int value) {
        Node* newNode = new Node(value);

        // Case 1: list empty → new node becomes start
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Case 2: walk until last node
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    void Print() {
        Node* current = head;
        while (current != NULL) {  // traverse until end
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    linkedlist list;

    list.Append(10);
    list.Append(20);
    list.Append(30);

    list.Print();

    return 0;
}
