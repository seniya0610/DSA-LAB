#include <iostream>
using namespace std;

class Stack
{
    int top;
    int capacity;
    char *arr;

public:
    Stack(int size)
    {
        capacity = size;
        top = -1;
        arr = new char[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(char x)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (isEmpty())
            return '\0';
        return arr[top];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Convert Infix to Postfix
string infixToPostFix(string infix)
{
    Stack s(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
        {
            postfix += c;
        }

        else if (c == '(')
        {
            s.push(c);
        }

        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop();
        }

        else
        {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek()))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}

int main()
{
    string infix = "A+(B*C-(D/E^F)*G)*H";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostFix(infix) << endl;

    return 0;
}
