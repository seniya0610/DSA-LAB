#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    void insertion(int value)
    {
        Node *temp = new Node(value);

        if (root == nullptr)
        {
            root = temp;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->data)
            parent->left = temp;
        else
            parent->right = temp;
    }

    void search(Node *node, int value)
    {
        if (node == nullptr)
        {
            cout << "Value not found in the tree." << endl;
            return;
        }
        if (node->data == value)
        {
            cout << "Value found in the tree." << endl;
            return;
        }
        if (value < node->data)
            search(node->left, value);
        else
            search(node->right, value);
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
};

int main()
{
    BinaryTree tree;
    tree.insertion(50);
    tree.insertion(30);
    tree.insertion(20);
    tree.insertion(40);
    tree.insertion(70);
    tree.insertion(60);
    tree.insertion(80);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    int searchValue;
    cout << "Enter value to search: ";
    cin >> searchValue;
    tree.search(tree.root, searchValue);

    return 0;
}
