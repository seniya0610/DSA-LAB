#include <iostream>
using namespace std;

struct Job {
    int id;
    int priority;
};

class Queue {
    int front, rear, size;
    Job *arr;
public:
    Queue(int s) {
        size = s;
        arr = new Job[size];
        front = rear = -1;
    }

    bool isFull() {
        return (rear == size - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(Job j) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = j;
    }

    Job dequeue() {
        Job temp = {-1, -1};
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return temp;
        }
        return arr[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Jobs in Queue (Arrival Order): ";
        for (int i = front; i <= rear; i++)
            cout << "[ID:" << arr[i].id << " P:" << arr[i].priority << "] ";
        cout << endl;
    }
};

class Stack {
    int top, size;
    Job *arr;
public:
    Stack(int s) {
        size = s;
        arr = new Job[size];
        top = -1;
    }

    bool isFull() {
        return (top == size - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(Job j) {
        if (isFull()) {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = j;
    }

    Job pop() {
        Job temp = {-1, -1};
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return temp;
        }
        return arr[top--];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Jobs in Stack (Execution Order - Top First): ";
        for (int i = top; i >= 0; i--)
            cout << "[ID:" << arr[i].id << " P:" << arr[i].priority << "] ";
        cout << endl;
    }
};

int main() {
    Queue q(5);
    Stack s(5);

    q.enqueue({101, 3});
    q.enqueue({102, 1});
    q.enqueue({103, 4});
    q.enqueue({104, 2});

    q.display();

    cout << "\nProcessing jobs (Higher priority -> pushed later on stack):\n";

    while (!q.isEmpty()) {
        Job j = q.dequeue();

        s.push(j);
        cout << "Pushed Job ID: " << j.id << " (Priority " << j.priority << ") onto Stack\n";
    }

    cout << endl;
    s.display();

    cout << "\nExecuting jobs from Stack:\n";
    while (!s.isEmpty()) {
        Job executed = s.pop();
        cout << "Executing Job ID: " << executed.id
             << " (Priority " << executed.priority << ")\n";
    }

    return 0;
}
