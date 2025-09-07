#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int d) : data(d), next(nullptr), child(nullptr) {}
};

class Linkedlist
{
public:
    Node *head;

    Linkedlist() : head(nullptr) {}

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

    void AppendChild(Node *parent, Linkedlist &childList)
    {
        if (!parent)
        {
            return;
        }
        parent->child = childList.head;
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

    void flatten()
    {
        if (!head)
        {
            return;
        }

        Node *current = head;
        Node *N = nullptr;

        while (current != nullptr)
        {
            if (current->child != nullptr)
            {
                // Save next node
                N = current->next;

                // Recursively flatten child list first
                Linkedlist childList;
                childList.head = current->child;
                childList.flatten();

                // Attach child
                current->next = current->child;
                current->child = nullptr; // clear child pointer

                // Find tail of the flattened child
                Node *temp = current->next;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }

                temp->next = N;
            }

            current = current->next;
        }
    }
};

int main()
{
    Linkedlist LL;
    LL.Append(1);
    LL.Append(2);
    LL.Append(3);

    Linkedlist childList;
    childList.Append(4);
    childList.Append(5);

    LL.AppendChild(LL.head->next, childList);

    cout << "Before flatten: ";
    LL.display();

    LL.flatten();

    cout << "After flatten: ";
    LL.display();
}
