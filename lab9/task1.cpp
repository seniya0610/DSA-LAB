#include <iostream>
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

    // left rotate
    Node *rightRotate(Node *n)
    {
        Node *x = n->left;
        Node *T2 = x->right;

        x->right = n;
        n->left = T2;

        updateheight(n);
        updateheight(x);

        return x;
    }

    Node *leftRotate(Node *n)
    {
        Node *x = n->right;
        Node *T2 = x->left;

        x->left = n;
        n->right = T2;

        updateheight(n);
        updateheight(x);

        return x;
    }

    Node *findmin(Node *n)
    {
        Node *current = n;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *insert(Node *n, int key)
    {
        // step one: perform normal BST insertion
        // base case: found a null position to insert the new node
        if (n == nullptr)
        {
            return new Node(key);
        }

        // traverse the tree to find the correct insertion point
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
        else if (key < n->data)
        {
            n->right = deleteNode(n->right, key);
        }
        else
        {
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

public:
    Node *root;
    AVLtree() : root(nullptr) {}

    void insertmain(int key)
    {
        root = insert(root, key);
        cout << getheight(root) << endl;
    }

    void deletemain(int key)
    {
        root = deleteNode(root, key);
        cout << getheight(root) << endl;
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

int main(){
    AVLtree studentRoster;
    studentRoster.insertmain(10);
    studentRoster.insertmain(20);
    studentRoster.insertmain(30); 

    studentRoster.insertmain(5);
    studentRoster.insertmain(2);

    studentRoster.insertmain(15); 
    studentRoster.insertmain(17); 

    studentRoster.insertmain(40);
    studentRoster.insertmain(35);

    cout << "Tree Inorder Traversal (Sorted):" << endl;
    studentRoster.inorder(studentRoster.root);
  

    cout << "\n--- Deletion Sequence (Testing rebalancing) ---" << endl;
    studentRoster.deletemain(5);

    studentRoster.deletemain(17);
    
    studentRoster.deletemain(20);     
    studentRoster.deletemain(40);

    cout << "Final Inorder Traversal after Deletions:" << endl;
    studentRoster.inorder(studentRoster.root);

    return 0;
}
