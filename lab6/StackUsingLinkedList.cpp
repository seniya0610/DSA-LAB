// Implement a stack using linked lists.
#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;

    Node(string value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Stack
{
public:
    Node *head;
    Node *top; // tail

    Stack() : head(nullptr), top(nullptr) {}

    void push(string value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            top = newNode;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }

    string pop()
    {
        if (!head)
        {
            cout << "Stack Underflow" << endl;
            return "";
        }
        string poppedValue = top->data;
        if (head == top)
        {
            delete top;
            head = nullptr;
            top = nullptr;
            return poppedValue;
        }
        Node *prevNode = top->prev;
        delete top;
        top = prevNode;
        top->next = nullptr;
        return poppedValue;
    }

    string peek()
    {
        if (!top)
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        return top->data;
    }

    void display()
    {
        if (!top)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *point = top;
        while (point)
        {
            cout << point->data << " ";
            point = point->prev;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push("10");
    s.push("20");
    s.push("30");
    s.display();
    cout << s.peek() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << s.peek() << endl;
    return 0;
}
