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

    linkedlist() : head(nullptr) {};

    void Append(int d)
    {

        Node *point = new Node(d);

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

    void revbyk(int k)
    {

        if (head == nullptr || k <= 1)
        {
            return;
        }

        Node *temp = new Node(0);
        temp->next = head;

        Node *current = head;
        Node *prevEnd = temp;

        while (current != nullptr)
        {
            Node *GS = current; // group start
            Node *prev = nullptr;
            Node *N = nullptr;
            int count = 0;

            while (current != nullptr && count < k)
            {
                N = current->next;
                current->next = prev;
                prev = current;
                current = N;
                count++;
            }
            prevEnd->next = prev;
            prevEnd = GS;
        };

        head = temp->next;
        delete temp;
    }
};

int main()
{
    linkedlist list;

    for (int i = 1; i <= 8; i++)
    {
        list.Append(i);
    }

    cout << "Original list: ";
    list.display();

    list.revbyk(3);
    cout << "Reversed in groups of 3: ";
    list.display();

    return 0;
}
