#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
public:
    Node* root;

    AVL() { root = nullptr; }

    int height(Node* n) {
        if (!n) return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (!n) return 0;
        return height(n->left) - height(n->right);
    }

    void updateHeight(Node* n) {
        n->height = 1 + max(height(n->left), height(n->right));
    }

    // --------------------------------------
    // ROTATIONS
    // --------------------------------------
    Node* rightRotate(Node* y) {
        cout << "Rotation performed: RIGHT ROTATION on " << y->key << endl;

        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* leftRotate(Node* x) {
        cout << "Rotation performed: LEFT ROTATION on " << x->key << endl;

        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // --------------------------------------
    // INSERT
    // --------------------------------------
    Node* insert(Node* node, int key) {
        if (!node) {
            cout << "Inserted: " << key << endl;
            return new Node(key);
        }

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // duplicates not allowed

        updateHeight(node);

        int balance = getBalance(node);

        // Print balance factor of affected node
        cout << "Balance factor of " << node->key << " = " << balance << endl;

        // Cases
        // 1. LL Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // 2. RR Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // 3. LR Case
        if (balance > 1 && key > node->left->key) {
            cout << "Rotation performed: LEFT-then-RIGHT on " << node->key << endl;
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 4. RL Case
        if (balance < -1 && key < node->right->key) {
            cout << "Rotation performed: RIGHT-then-LEFT on " << node->key << endl;
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // --------------------------------------
    // DELETE
    // --------------------------------------
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            cout << "Deleting: " << key << endl;

            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;

                if (!temp) { // no child
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) return root;

        updateHeight(root);
        int balance = getBalance(root);

        cout << "Balance factor of " << root->key << " = " << balance << endl;

        // Rebalance cases
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            cout << "Rotation performed: LEFT-then-RIGHT on " << root->key << endl;
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            cout << "Rotation performed: RIGHT-then-LEFT on " << root->key << endl;
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Utility to print height after each operation
    void printHeight() {
        cout << "Current AVL Tree Height = " << height(root) << endl << endl;
    }
};

int main() {
    AVL t;

    // INSERTIONS
    t.root = t.insert(t.root, 50);
    t.printHeight();

    t.root = t.insert(t.root, 20);
    t.printHeight();

    t.root = t.insert(t.root, 70);
    t.printHeight();

    t.root = t.insert(t.root, 10);
    t.printHeight();

    t.root = t.insert(t.root, 30);
    t.printHeight();

    // DELETIONS
    t.root = t.deleteNode(t.root, 20);
    t.printHeight();

    t.root = t.deleteNode(t.root, 30);
    t.printHeight();

    t.root = t.deleteNode(t.root, 50);
    t.printHeight();

    return 0;
}
