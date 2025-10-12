// Implement a circular queue using arrays. Handle the following conditions correctly:
// 1. Enqueue when rear wraps around
// 2. Dequeue when front moves ahead
// 3. Prevent overflow when queue is full

#include <iostream>
using namespace std;

class Queue
{
    int front, rear, capacity;
    int *arr;

public:
    Queue(int size)
    {
        capacity = size;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    void Enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty())
        {
            rear = front = 0;
            arr[rear] = x;
            return;
        }
        if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % capacity == front);
    }

    int Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int dequeuedValue = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            if (front == capacity - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
        return dequeuedValue;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
            {
                break;
            }
            if (i == capacity - 1)
                i = 0;
            else
            {
                i++;
            }
        }
    }
};

int main(){
    Queue q(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.display();
    cout << "Dequeued element: " << q.Dequeue() << endl;
    q.display();
    return 0;
}
