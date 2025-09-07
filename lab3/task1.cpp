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

    void Append(int e)
    {
        Node *point = new Node(e);
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
        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isPalindrome()
    {
        if (head == nullptr || head->next == nullptr)
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
            first = first->next;
            second = second->next;
        }

        revlist(secondhalf);
        return palindrome;
    }

private:
    Node *revlist(Node *ptr)
    {
        Node *previous = nullptr;
        Node *current = ptr;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }

    Node *middle()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
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
