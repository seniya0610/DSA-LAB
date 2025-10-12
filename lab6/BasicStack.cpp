// Implement a stack using arrays. Support the following operations:
// 1. Push an element
// 2. Pop an element
// 3. Peek (top element)
// 4. Display stack contents

#include <iostream>
using namespace std;

class Stack{
    int capacity;
    int top;
    int *arr;

    public:
    Stack(int size){
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }

    void push(int x){
        if(top == capacity - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        top--;
        return arr[top];
    }

    int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return;
        }
        for(int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped element: " << s.pop() << endl;
    s.display();
    return 0;
}
