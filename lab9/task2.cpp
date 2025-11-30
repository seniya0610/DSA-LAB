#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int r) : data(r), left(nullptr), right(nullptr), height(1) {}
};

class AVLtree
{

    int getheight(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return n->height;
    }

    void updateheight(Node *n)
    {
        if (n != nullptr)
        {
            n->height = 1 + max(getheight(n->left), getheight(n->right));
        }
    }

    int balanceFactor(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return getheight(n->left) - getheight(n->right);
    }

    // Right Rotate (for LL case)
    Node *rightRotate(Node *n)
    {
        Node *x = n->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = n;
        n->left = T2;

        // Update heights
        updateheight(n);
        updateheight(x);

        return x;
    }

    // Left Rotate (for RR case)
    Node *leftRotate(Node *n)
    {
        Node *x = n->right;
        Node *T2 = x->left;

        // Perform rotation
        x->left = n;
        n->right = T2;

        // Update heights
        updateheight(n);
        updateheight(x);

        return x;
    }

    Node *findmin(Node *n)
    {
        Node *current = n;
        while (current != nullptr && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *insert(Node *n, int key)
    {
        // step one: perform normal BST insertion
        if (n == nullptr)
        {
            return new Node(key);
        }

        if (key < n->data)
        {
            n->left = insert(n->left, key);
        }
        else if (key > n->data)
        {
            n->right = insert(n->right, key);
        }
        else
        {
            return n; // No duplicates allowed
        }

        // step two: update height
        updateheight(n);

        // step three: get balance factor
        int balance = balanceFactor(n);

        // step four: perform rotations if unbalanced
        if (balance > 1 && key < n->left->data) // left left case
        {
            return rightRotate(n);
        }
        if (balance < -1 && key > n->right->data) // right right case
        {
            return leftRotate(n);
        }
        if (balance > 1 && key > n->left->data) // left right case
        {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
        if (balance < -1 && key < n->right->data) // right left case
        {
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }

        return n;
    }

    Node *deleteNode(Node *n, int key)
    { // AVL deletion
        if (n == nullptr)
        {
            return n;
        }

        if (key < n->data)
        {
            n->left = deleteNode(n->left, key);
        }
        else if (key > n->data)
        {
            n->right = deleteNode(n->right, key);
        }
        else
        {
            // Node found
            if (n->left == nullptr && n->right == nullptr)
            {
                delete n;
                return nullptr;
            }
            else if (n->left == nullptr)
            {
                Node *temp = n->right;
                delete n;
                return temp;
            }
            else if (n->right == nullptr)
            {
                Node *temp = n->left;
                delete n;
                return temp;
            }
            else
            {
                Node *temp = findmin(n->right);
                n->data = temp->data;
                n->right = deleteNode(n->right, temp->data);
            }
        }

        // If node becomes null after deletion
        if (n == nullptr)
        {
            return n;
        }

        // Rebalance
        updateheight(n);
        int b = balanceFactor(n);

        if (b > 1 && balanceFactor(n->left) >= 0) // left left case
        {
            return rightRotate(n);
        }
        if (b < -1 && balanceFactor(n->right) <= 0) // right right case
        {
            return leftRotate(n);
        }
        if (b > 1 && balanceFactor(n->left) < 0) // left right case
        {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
        if (b < -1 && balanceFactor(n->right) > 0) // right left case
        {
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }

        return n;
    }

    // New helper for range query
    void rangeQueryHelper(Node *n, int x, int y)
    {
        if (n == nullptr)
        {
            return;
        }

        // Traverse left subtree only if the left child could contain values >= x
        if (x < n->data)
        {
            rangeQueryHelper(n->left, x, y);
        }
        // Print the node's data if it is within the range [x, y]
        if (x <= n->data && n->data <= y)
        {
            cout << n->data << " ";
        }
        // Traverse right subtree only if the right child could contain values <= y
        if (y > n->data)
        {
            rangeQueryHelper(n->right, x, y);
        }
    }

public:
    Node *root;
    AVLtree() : root(nullptr) {}

    void insertmain(int key)
    {
        root = insert(root, key);
    }

    void deletemain(int key)
    {
        root = deleteNode(root, key);
    }

    // New public function for range query
    void rangeQuery(int x, int y)
    {
        cout << "Prices between " << x << " and " << y << ": ";
        rangeQueryHelper(root, x, y);
        cout << endl;
    }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main()
{
    AVLtree productPrices;

    productPrices.insertmain(50);
    productPrices.insertmain(20);
    productPrices.insertmain(10);
    productPrices.insertmain(40);
    productPrices.insertmain(30);
    productPrices.insertmain(60);
    productPrices.insertmain(80);
    productPrices.insertmain(70);
    productPrices.insertmain(90);
    productPrices.insertmain(15);
    productPrices.insertmain(55);

    cout << "Product Prices (Inorder Traversal):" << endl;
    productPrices.inorder(productPrices.root);

    cout << "\n--- Range Query Operations ---" << endl;
    productPrices.rangeQuery(35, 65);
    productPrices.rangeQuery(1, 100);
    productPrices.rangeQuery(10, 30);

    productPrices.rangeQuery(75, 95);

    productPrices.deletemain(15);
    productPrices.deletemain(90);

    cout << "Final Inorder Traversal after Deletions:" << endl;
    productPrices.inorder(productPrices.root);

    return 0;
}
