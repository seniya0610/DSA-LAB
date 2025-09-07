#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *N;

    Node(int d) : data(d), N(nullptr) {}
};

class linkedlist
{
public:
    Node *head;

    linkedlist() : head(nullptr) {}

    void Append(int e)
    {
        Node *point = new Node(e);
        if (head == nullptr)
        {
            head = point;
            return;
        }
        Node *temp = head;
        while (temp->N != nullptr)
        {
            temp = temp->N;
        }
        temp->N = point;
    }

    void display()
    {
        Node *temp = head;
        while (temp->N != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->N;
        }
        cout << endl;
    }

    bool isPalindrome()
    {
        if (head == nullptr || head->N == nullptr)
        {
            return true;
        }

        Node *mid = middle();
        Node *first = head;
        Node *secondhalf = revlist(mid);
        Node *second = secondhalf;
        bool palindrome = true;

        while (second != nullptr)
        {
            if (first->data != second->data)
            {
                palindrome = false;
                break;
            }
            first = first->N;
            second = second->N;
        }

        revlist(secondhalf);
        return palindrome;
    }

private:
    Node *revlist(Node *ptr)
    {
        Node *previous = nullptr;
        Node *current = ptr;
        Node *N = nullptr;

        while (current != nullptr)
        {
            N = current->N;
            current->N = previous;
            previous = current;
            current = N;
        }
        return previous;
    }

    Node *middle()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->N != nullptr)
        {
            slow = slow->N;
            fast = fast->N->N;
        }
        return slow; // middle node
    }
};

int main()
{
    linkedlist list;
    list.Append(1);
    list.Append(2);
    list.Append(2);
    list.Append(1);

    cout << (list.isPalindrome() ? "Palindrome" : "Not Palindrome") << endl;
}
