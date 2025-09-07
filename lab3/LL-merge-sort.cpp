#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr) {}
};

class linkedlist
{
public:
    Node *head;

    linkedlist() : head(nullptr) {}

    void Append(int s)
    {
        Node *point = new Node(s);
        if (head == nullptr)
        {
            head = point;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = point;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Node *mergeSorted(Node *firstLL, Node *secondLL)
{
    if (!firstLL && !secondLL)
    {
        return nullptr;
    }
    if (!firstLL)
    {
        return secondLL;
    }
    if (!secondLL)
    {
        return firstLL;
    }

    Node FIRST(0); //to keep track of the first node
    Node *N = &FIRST; //tail pointer that keeps updating to the next and attaching nodes

    while (firstLL && secondLL)
    {
        if (firstLL->data <= secondLL->data)
        {
            N->next = firstLL;
            firstLL = firstLL->next;
        }
        else
        {
            N->next = secondLL;
            secondLL = secondLL->next;
        }
        // to ensure this pointer is always at the end of the list and the pointer is moved forward
        N = N->next;
    }

    // When one list ends, the other list may still have nodes left.
    // tail->next connects directly to whichever list is non-empty.
    if (firstLL)
    {
        N->next = firstLL;
    }
    if (secondLL)
    {
        N->next = secondLL;
    }

    return FIRST.next;
}

int main()
{
    linkedlist list1;
    list1.Append(2);
    list1.Append(4);
    list1.Append(5);

    linkedlist list2;
    list2.Append(1);
    list2.Append(3);
    list2.Append(4);

    cout << "list 1: " << endl;
    list1.display();

    cout << "list 2: " << endl;
    list2.display();

    Node *mergeHead = mergeSorted(list1.head, list2.head);

    cout << "Merged: ";
    Node *temp = mergeHead;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
