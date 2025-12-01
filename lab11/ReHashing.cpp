#include <iostream>
using namespace std;

// Hashing with Linear Probing

class Node
{
public:
    int key;
    int value;

    Node(int k, int v) : key(k), value(v) {}
    Node() : key(-1), value(-1) {} // empty slot
};

class LinearHash
{
public:
    int size;
    Node *table;

    LinearHash(int s) : size(s)
    {
        table = new Node[size];
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int key, int value)
    {
        int index = hashFunction(key);

        // find empty slot using linear probing
        int start = index;
        while (table[index].key != -1)
        {
            index = (index + 1) % size;
            if (index == start)
            {
                cout << "Hash Table Full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = Node(key, value);
    }

    float loadFactor()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
            if (table[i].key != -1)
            {
                count++;
            }

        return (float)count / size;
    }

    void display()
    {
        cout << "Hash Table (Linear Probing):";
        for (int i = 0; i < size; i++)
        {
            if (table[i].key != -1)
                cout << "Index " << i << " -> Key: " << table[i].key << ", Value: " << table[i].value << endl;
            else
                cout << "Index " << i << " -> Empty" << endl;
        }
    }

    void deleteNode(int key)
    {
        int index = hashFunction(key);
        int start = index;

        while (table[index].key != -1)
        {
            if (table[index].key == key)
            {
                table[index] = Node(); // reset to empty
                cout << "Deleted key " << key << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start)
                break;
        }
        cout << "Key " << key << " not found!" << endl;
    }

    int nextPrime(int n)
    {
        while (true)
        {
            bool isPrime = true;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                return n;
            n++;
        }
    }

    void rehash()
    {
        int oldSize = size;
        Node *oldTable = table;

        size = nextPrime(2 * oldSize);
        table = new Node[size];

        for (int i = 0; i < oldSize; i++)
        {
            if (oldTable[i].key != -1)
            {
                insert(oldTable[i].key, oldTable[i].value);
            }
        }

        delete[] oldTable;
    }
};

int main()
{
    LinearHash hashTable(5);

    hashTable.insert(1, 100);
    hashTable.insert(6, 200);  // Should collide with index 1
    hashTable.insert(11, 300); // Should collide with index 1
    hashTable.insert(2, 400);
    hashTable.insert(3, 500);

    hashTable.display();

    cout << "Load Factor: " << hashTable.loadFactor() << endl;

    cout << "\nRehashing...\n" << endl;
    hashTable.rehash();
    hashTable.display();

    return 0;
}
