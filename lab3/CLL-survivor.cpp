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
    Node *tail;
    int size;

    linkedlist() : head(nullptr), tail(nullptr), size(0) {}

    void Append(int d)
    {
        Node *newNode = new Node(d);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head; // make circular
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // maintain circular link
        }
        size++;
    }

    void deleteNode(Node *todelete)
    {
        if (head == nullptr || todelete == nullptr)
            return;

        // Case 1: Only one node
        if (head == tail && head == todelete)
        {
            delete todelete;
            head = tail = nullptr;
            size--;
            return;
        }

        // Case 2: Deleting head
        if (todelete == head)
        {
            head = head->next;
            tail->next = head;
            delete todelete;
            size--;
            return;
        }

        // Case 3: Deleting tail
        if (todelete == tail)
        {
            Node *prev = head;
            while (prev->next != tail)
                prev = prev->next;

            prev->next = head;
            delete tail;
            tail = prev;
            size--;
            return;
        }

        // Case 4: Deleting middle node
        Node *prev = head;
        while (prev->next != todelete)
            prev = prev->next;

        prev->next = todelete->next;
        delete todelete;
        size--;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = head;
        cout << "Circular List: ";
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    int josephus(int k)
    {
        if (head == nullptr)
            return -1;
        if (size == 1)
            return head->data;

        Node *prev = tail;
        Node *current = head;

        while (size > 1)
        {
            for (int count = 1; count < k; count++)
            {
                prev = current;
                current = current->next;
            }

            Node *temp = current;
            current = current->next;
            deleteNode(temp);
        }

        return head->data;
    }
};

int main()
{
    linkedlist cll;
    // Josephus with n=7, k=3
    for (int i = 1; i <= 7; i++)
        cll.Append(i);

    cll.display();

    int survivor = cll.josephus(3);
    cout << "Survivor: " << survivor << endl;

    return 0;
}
