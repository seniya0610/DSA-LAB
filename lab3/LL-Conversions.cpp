#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class DNode {
public:
    int data;
    DNode *next;
    DNode *prev;
    DNode(int d) : data(d), next(nullptr), prev(nullptr) {}
};

void convertToCLL(Node *head) {
    if (!head) return;
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
}

DNode* convertToDLL(Node *head) {
    if (head == nullptr) {
        cout << "list empty" << endl;
        return nullptr;
    }

    DNode *newHead = new DNode(head->data);
    DNode *dllCurr = newHead;
    Node *sllCurr = head->next;

    while (sllCurr != nullptr) {
        DNode *newNode = new DNode(sllCurr->data);
        dllCurr->next = newNode;
        newNode->prev = dllCurr;

        dllCurr = newNode;
        sllCurr = sllCurr->next;
    }

    return newHead;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void freeListD(DNode* head) {
    while (head != nullptr) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    list1->next->next->next = new Node(4);
    list1->next->next->next->next = new Node(5);
    list1->next->next->next->next->next = new Node(6);

    DNode* doublyhead = convertToDLL(list1);

    convertToCLL(list1);

    freeList(list1);
    freeListD(doublyhead);
}
