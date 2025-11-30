#include <iostream>
using namespace std;

// hashing using linked list

class Node
{
public:
    int key;
    int value;
    Node *next;

    Node(int k = -1, int v = -1) : key(k), value(v), next(nullptr) {}
};

class HashUsingLL
{
public:
    int size;
    Node **table;

    HashUsingLL(int s) : size(s)
    {
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }

    ~HashUsingLL()
    {
        for (int i = 0; i < size; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int key, int value)
    {
        int index = hashFunction(key);
        Node *n = new Node(key, value);

        // directly insert if slot is empty
        if (table[index] == nullptr)
        {
            table[index] = n;
        }
        else
        {
            // Check if key already exists
            Node *current = table[index];
            Node *prev = nullptr;

            while (current != nullptr)
            {
                if (current->key == key)
                {
                    // Key exists, update value
                    current->value = value;
                    delete n; // Don't need the new node we created
                    return;
                }
                prev = current;
                current = current->next;
            }
            prev->next = n;
        }
    }

    int search(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << "[" << current->key << ":" << current->value << "] -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }

    void deleteNode(int key)
    {
        int index = hashFunction(key);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                { // Deleting the first node in the chain
                    table[index] = current->next;
                    delete current;
                    return;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
        cout << "Key " << key << " not found!" << endl;
    }
};

int main()
{
    // Test the hash table
    HashUsingLL hashTable(5);

    hashTable.insert(1, 100);
    hashTable.insert(6, 200);  // Should collide with index 1
    hashTable.insert(11, 300); // Should collide with index 1
    hashTable.insert(2, 400);
    hashTable.insert(3, 500);

    hashTable.display();

    cout << "\nSearch for key 6: " << hashTable.search(6) << endl;
    cout << "Search for key 11: " << hashTable.search(11) << endl;
    cout << "Search for key 99: " << hashTable.search(99) << endl;

    return 0;
}
