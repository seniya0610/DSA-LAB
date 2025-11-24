#include <iostream>
#include <cstdlib>
using namespace std;

// =============================================
// MAX HEAP CLASS
// =============================================
class MaxHeap {
private:
    int* heap;   
    int capacity;
    int size;    
    
    int parent(int i) {
        return (i - 1) / 2;
    }
    
    int leftChild(int i) {
        return (2 * i) + 1;
    }
    
    int rightChild(int i) {
        return (2 * i) + 2;
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Heapify up for maintaining max heap property after insertion
    void heapifyUp(int i) {
        // Continue until root or heap property is satisfied
        while (i > 0 && heap[parent(i)] < heap[i]) {
            // Swap with parent if parent is smaller
            swap(heap[i], heap[parent(i)]);
            i = parent(i);  // Move to parent position
        }
    }
    
    // Heapify down for maintaining max heap property after deletion
    void heapifyDown(int i) {
        int largest = i;        // Assume current node is largest
        int left = leftChild(i);   // Left child index
        int right = rightChild(i); // Right child index
        
        // Check if left child exists and is larger than current
        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        
        // Check if right child exists and is larger than current largest
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        
        // If largest is not current node, swap and continue heapifying
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);  // Recursively heapify affected subtree
        }
    }
    
public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }
    
    // Insert element into heap
    void insert(int value) {
        // Check if heap is full
        if (size >= capacity) {
            cout << "Heap is full! Cannot insert " << value << endl;
            return;
        }
        
        // Insert at end
        heap[size] = value;
        size++;
        
        // Maintain heap property by moving element up
        heapifyUp(size - 1);
        cout << "Inserted into MaxHeap: " << value << endl;
    }
    
    // Remove and return maximum element
    int removeMax() {
        // Check if heap is empty
        if (size <= 0) {
            cout << "Heap is empty! Cannot remove." << endl;
            return -1;
        }
        
        // If only one element exists
        if (size == 1) {
            size--;
            cout << "Removed from MaxHeap: " << heap[0] << endl;
            return heap[0];
        }
        
        // Store root value
        int root = heap[0];
        
        // Replace root with last element
        heap[0] = heap[size - 1];
        size--;
        
        // Maintain heap property by heapifying down from root
        heapifyDown(0);
        
        cout << "Removed from MaxHeap: " << root << endl;
        return root;
    }
    
    // Get maximum element without removing
    int getMax() {
        // Check if heap is empty
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];  // Root is maximum in max heap
    }
    
    // Check if heap is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Get current size of heap
    int getSize() {
        return size;
    }
    
    // Display heap array
    void printHeap() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    // Build max heap from existing array (Heapify)
    void buildHeap(int arr[], int n) {
        // Check if array fits in heap
        if (n > capacity) {
            cout << "Array too large for heap capacity!" << endl;
            return;
        }
        
        // Copy array to heap
        for (int i = 0; i < n; i++) {
            heap[i] = arr[i];
        }
        size = n;
        
        // Heapify all non-leaf nodes starting from last non-leaf node
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
        
        cout << "Built MaxHeap from array" << endl;
    }
};

// =============================================
// MIN HEAP CLASS
// =============================================
class MinHeap {
private:
    int* heap;
    int capacity;
    int size;
    
    // Get parent index
    int parent(int i) {
        return (i - 1) / 2;
    }
    
    // Get left child index
    int leftChild(int i) {
        return (2 * i) + 1;
    }
    
    // Get right child index
    int rightChild(int i) {
        return (2 * i) + 2;
    }
    
    // Swap two elements in heap
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // Heapify up for maintaining min heap property after insertion
    void heapifyUp(int i) {
        // Continue until root or heap property is satisfied
        while (i > 0 && heap[parent(i)] > heap[i]) {
            // Swap with parent if parent is larger
            swap(heap[i], heap[parent(i)]);
            i = parent(i);  // Move to parent position
        }
    }
    
    // Heapify down for maintaining min heap property after deletion
    void heapifyDown(int i) {
        int smallest = i;     // Assume current node is smallest
        int left = leftChild(i);   // Left child index
        int right = rightChild(i); // Right child index
        
        // Check if left child exists and is smaller than current
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        
        // Check if right child exists and is smaller than current smallest
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        // If smallest is not current node, swap and continue heapifying
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);  // Recursively heapify affected subtree
        }
    }
    
public:
    // Constructor
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];  // Allocate memory for heap
    }
    
    // Destructor
    ~MinHeap() {
        delete[] heap;  // Free allocated memory
    }
    
    // Insert element into heap
    void insert(int value) {
        // Check if heap is full
        if (size >= capacity) {
            cout << "Heap is full! Cannot insert " << value << endl;
            return;
        }
        
        // Insert at end
        heap[size] = value;
        size++;
        
        // Maintain heap property by moving element up
        heapifyUp(size - 1);
        
        cout << "Inserted into MinHeap: " << value << endl;
    }
    
    // Remove and return minimum element
    int removeMin() {
        // Check if heap is empty
        if (size <= 0) {
            cout << "Heap is empty! Cannot remove." << endl;
            return -1;
        }
        
        // If only one element exists
        if (size == 1) {
            size--;
            cout << "Removed from MinHeap: " << heap[0] << endl;
            return heap[0];
        }
        
        // Store root value
        int root = heap[0];
        
        // Replace root with last element
        heap[0] = heap[size - 1];
        size--;
        
        // Maintain heap property by heapifying down from root
        heapifyDown(0);
        
        cout << "Removed from MinHeap: " << root << endl;
        return root;
    }
    
    // Get minimum element without removing
    int getMin() {
        // Check if heap is empty
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];  // Root is minimum in min heap
    }
    
    // Check if heap is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Get current size of heap
    int getSize() {
        return size;
    }
    
    // Display heap array
    void printHeap() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        cout << "Min Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    // Build min heap from existing array (Heapify)
    void buildHeap(int arr[], int n) {
        // Check if array fits in heap
        if (n > capacity) {
            cout << "Array too large for heap capacity!" << endl;
            return;
        }
        
        // Copy array to heap
        for (int i = 0; i < n; i++) {
            heap[i] = arr[i];
        }
        size = n;
        
        // Heapify all non-leaf nodes starting from last non-leaf node
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
        
        cout << "Built MinHeap from array" << endl;
    }
};

// =============================================
// MAIN FUNCTION WITH DEMONSTRATION
// =============================================
int main() {
    cout << "=== HEAP AND PRIORITY QUEUE IMPLEMENTATION ===" << endl;
    cout << endl;
    
    // Test Priority Queue (Linked List)
    cout << "--- PRIORITY QUEUE (LINKED LIST) ---" << endl;
    PriorityQueue pq;
    
    // Insert elements
    pq.insert(30);
    pq.insert(10);
    pq.insert(20);
    pq.insert(40);
    pq.insert(5);
    
    // Display queue
    pq.printQueue();
    
    // Peek and remove
    cout << "Highest priority: " << pq.peek() << endl;
    pq.remove();
    cout << "After removal - Highest priority: " << pq.peek() << endl;
    pq.printQueue();
    
    cout << endl;
    
    // Test Max Heap
    cout << "--- MAX HEAP ---" << endl;
    MaxHeap maxHeap(10);
    
    // Insert elements
    maxHeap.insert(30);
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(40);
    maxHeap.insert(5);
    
    // Display heap
    maxHeap.printHeap();
    
    // Get and remove max
    cout << "Current max: " << maxHeap.getMax() << endl;
    maxHeap.removeMax();
    cout << "After removal - Current max: " << maxHeap.getMax() << endl;
    maxHeap.printHeap();
    
    // Test build heap from array
    int arr1[] = {15, 25, 35, 45, 55};
    maxHeap.buildHeap(arr1, 5);
    maxHeap.printHeap();
    
    cout << endl;
    
    // Test Min Heap
    cout << "--- MIN HEAP ---" << endl;
    MinHeap minHeap(10);
    
    // Insert elements
    minHeap.insert(30);
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(40);
    minHeap.insert(5);
    
    // Display heap
    minHeap.printHeap();
    
    // Get and remove min
    cout << "Current min: " << minHeap.getMin() << endl;
    minHeap.removeMin();
    cout << "After removal - Current min: " << minHeap.getMin() << endl;
    minHeap.printHeap();
    
    // Test build heap from array
    int arr2[] = {55, 45, 35, 25, 15};
    minHeap.buildHeap(arr2, 5);
    minHeap.printHeap();
    
    cout << endl;
    cout << "=== PROGRAM COMPLETED SUCCESSFULLY ===" << endl;
    
    return 0;
}
