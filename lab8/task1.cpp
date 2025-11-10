#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}

    int getdata()
    {
        return data;
    }
};

class Tree
{
private:
    Node *root;

public:
    Tree() : root(nullptr) {}

    Node *getroot()
    {
        return root;
    }
    
    void insertion(int data)
    {
        Node *temp = new Node(data);

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
            if (data < current->getdata())
                current = current->left;
            else
                current = current->right;
        }

        if (data < parent->getdata())
            parent->left = temp;
        else
            parent->right = temp;
    }

    void displayroot()
    {
        if (root)
            cout << "Root: " << root->getdata() << endl;
        else
            cout << "Tree is empty." << endl;
    }

    void displayleaf(Node *node)
    {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr)
        {
            cout << node->data << " ";
            return;
        }
        displayleaf(node->left);
        displayleaf(node->right);
    }

    void displayLevels(Node *node, int count)
    {
        if (node == nullptr)
            return;

        cout << "Node " << node->data << " is at level " << count << endl;

        displayLevels(node->left, count + 1);
        displayLevels(node->right, count + 1);
    }

    void displayheight(Node *node, int count)
    {
        if (node == nullptr)
            cout << count << endl;
        return;

        displayheight(node->left, count + 1);
        displayheight(node->right, count + 1);
    }
};

int main()
{
    Tree t;
    t.insertion(50);
    t.insertion(30);
    t.insertion(70);
    t.insertion(20);
    t.insertion(40);
    t.insertion(60);
    t.insertion(80);

    t.displayroot();

    cout << "\nLeaf nodes: ";
    t.displayleaf(t.getroot());
    cout << endl;

    cout << "\nLevels of each node:\n";
    t.displayheight(t.getroot(), 1);

    return 0;
}



