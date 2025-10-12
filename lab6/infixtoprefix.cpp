#include <iostream>
using namespace std;

class Stack {
    int top;
    int capacity;
    char *arr;

public:
    Stack(int size) {
        capacity = size;
        top = -1;
        arr = new char[capacity];
    }

    ~Stack() { delete[] arr; }

    bool isEmpty() { return top == -1; }

    void push(char x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string infix) {
    string prefix = "";
    Stack st(infix.length());

    // Traverse from right to left
    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        // Operand check (without isalnum)
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) {
            prefix = c + prefix;
        }

        // Closing bracket — push to stack
        else if (c == ')') {
            st.push(c);
        }

        // Opening bracket — pop until ')' found
        else if (c == '(') {
            while (!st.isEmpty() && st.peek() != ')') {
                prefix = st.pop() + prefix;
            }
            st.pop(); // remove ')'
        }

        // Operator
        else if (isOperator(c)) {
            while (!st.isEmpty() && getPrecedence(st.peek()) > getPrecedence(c)) {
                prefix = st.pop() + prefix;
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.isEmpty()) {
        prefix = st.pop() + prefix;
    }

    return prefix;
}

int main() {
    string infix = "A+(B*C-(D/E^F)*G)*H";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
}
