#include <iostream>
using namespace std;

// Hashing with Linear Probing

class Node {
public:
    int key;
    int value;

    Node(int k, int v) : key(k), value(v) {}
    Node() : key(-1), value(-1) {}  // empty slot
};

class LinearHash {
public:
    int size;
    Node *table;

    LinearHash(int s) : size(s) {
        table = new Node[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        // find empty slot using linear probing
        int start = index; 
        while (table[index].key != -1) {
            index = (index + 1) % size;
            if (index == start) { 
                cout << "Hash Table Full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = Node(key, value);
    }

    void search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].key != -1) {
            if (table[index].key == key) {
                cout << "Found key " << key << " with value: " << table[index].value << endl;
                return;
            }
            index = (index + 1) % size;

            if (index == start) break;
        }
        cout << "Key " << key << " NOT found!" << endl;
    }

    void deleteNode(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].key != -1) {
            if (table[index].key == key) {
                table[index] = Node(); // reset to empty
                cout << "Deleted key " << key << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        cout << "Key " << key << " not found!" << endl;
    }

    void display() {
        cout << "\nHash Table (Linear Probing):\n";
        for (int i = 0; i < size; i++) {
            if (table[i].key != -1)
                cout << "Index " << i << " -> Key: " << table[i].key << ", Value: " << table[i].value << endl;
            else
                cout << "Index " << i << " -> Empty\n";
        }
    }
};

int main() {
    LinearHash hash(10);

    hash.insert(23, 10);
    hash.insert(43, 20);
    hash.insert(13, 30);
    hash.insert(27, 40);
    hash.insert(34, 50);
    hash.insert(45, 60);
    hash.insert(26, 70);

    hash.display();

    cout << endl;
    hash.search(27);
    hash.search(55);

    cout << endl;
    hash.deleteNode(43);
    hash.display();

    return 0;
}
