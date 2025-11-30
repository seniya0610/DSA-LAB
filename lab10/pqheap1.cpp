#include <iostream>
using namespace std;

// priority_queue using heap

class Patient
{
public:
    string name;
    int SL;
    string time;

    Patient(string n, int s, string t)
    {
        name = n;
        SL = s;
        time = t;
    }
};

class MaxPriorityQueue
{
public:
    Patient *heap[300];
    int current = 0;

    bool isEmpty() const
    {
        return current == 0;
    }

    void swap(int i, int j)
    {
        Patient *temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    int getParentIndex(int i) const
    {
        return (i - 1) / 2;
    }

    int getLeftChildIndex(int i) const
    {
        return 2 * i + 1;
    }

    int getRightChildIndex(int i) const
    {
        return 2 * i + 2;
    }

    void shiftup(int i)
    {
        int parentIndex = getParentIndex(i);
        while (i > 0 && heap[i]->SL > heap[parentIndex]->SL)
        {
            swap(i, parentIndex);
            i = parentIndex;
            parentIndex = getParentIndex(i);
        }
    }

    void insert(Patient *p)
    {
        if (current >= 300)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        heap[current] = p;
        shiftup(current);
        current++;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "No patients in the queue" << endl;
            return;
        }
        cout << "Next patient: " << heap[0]->name << ", Severity Level: " << heap[0]->SL << ", Arrival Time: " << heap[0]->time << endl;
    }

    void shiftdown(int i)
    {
        while (true)
        {
            int largest = i;
            int leftIndex = getLeftChildIndex(i);
            int rightIndex = getRightChildIndex(i);

            if (leftIndex < current && heap[leftIndex]->SL > heap[largest]->SL)
            {
                largest = leftIndex;
            }
            if (rightIndex < current && heap[rightIndex]->SL > heap[largest]->SL)
            {
                largest = rightIndex;
            }
            if (largest != i)
            {
                swap(i, largest);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }

    Patient* removeRoot(){
        if (isEmpty()){
            cout << "No patients in the queue" << endl;
            return nullptr;
        }
        Patient* removedPatient = heap[0];
        heap[0] = heap[current - 1];
        current--;
        shiftdown(0);
        return removedPatient;
    }
    
    void displayAll() {
        if (isEmpty()) {
            cout << "No patients in the queue" << endl;
            return;
        }
        cout << "Patients in queue:" << endl;
        for (int i = 0; i < current; i++) {
            cout << i+1 << ". " << heap[i]->name << ", Severity: " << heap[i]->SL 
                 << ", Time: " << heap[i]->time << endl;
        }
    }
    
    int size() const {
        return current;
    }

    void updatePatientSeverity(int index, int newSL) {
        if (index < 0 || index >= current) {
            cout << "Invalid index!" << endl;
            return;
        }
        int oldSL = heap[index]->SL;
        heap[index]->SL = newSL;
        if (newSL > oldSL) {
            shiftup(index);
        } else if (newSL < oldSL) {
            shiftdown(index);
        }
    }

};

int main()
{
    MaxPriorityQueue pq;
    
    Patient* p1 = new Patient("John Doe", 5, "08:30");
    Patient* p2 = new Patient("Jane Smith", 8, "09:15");
    Patient* p3 = new Patient("Bob Johnson", 3, "10:00");
    
    pq.insert(p1);
    pq.insert(p2);
    pq.insert(p3);
    
    pq.displayAll();
    
    cout << "\n";
    pq.peek();
    
    cout << "\nProcessing next patient..." << endl;
    Patient* next = pq.removeRoot();
    if (next != nullptr) {
        cout << "Processing: " << next->name << endl;
    }
    
    cout << "\nRemaining patients:" << endl;
    pq.displayAll();
    
    delete p1;
    delete p2;
    delete p3;
    
    return 0;
}
