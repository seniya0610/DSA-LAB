// // Implement a linear queue using arrays with the following operations:
// 1. Enqueue
// 2. Dequeue
// 3. Display queue contents
// 4. Check if queue is empty/full

#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int capacity;
    int *arr;

public:
    Queue(int size)
    {
        capacity = size;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    void enqueue(int x)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int dequeuedValue = arr[front];
        front++;
        return dequeuedValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Dequeued element: " << q.dequeue() << endl;
    q.display();
    return 0;
}
