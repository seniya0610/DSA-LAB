#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class Queue
{
public:
    Node *arr[100];
    int front, rear;

    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    void push(Node *x)
    {
        arr[++rear] = x;
    }

    Node *pop()
    {
        return arr[front++];
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    void insert(int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
            return; // Important: return after creating root
        }

        Node *temp = root;
        Node *parent = nullptr; // Track parent to link new node

        while (temp != nullptr)
        {
            parent = temp; // Update parent before moving

            if (data < temp->data)
            {
                temp = temp->left;
            }
            else if (data > temp->data)
            {
                temp = temp->right;
            }
        }

        Node *newNode = new Node(data);

        if (data < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }

    void storeInArray(int output[]) // Store tree into array in BFS order
    {
        if (root == NULL)
            return;

        Queue q;
        q.push(root);

        int i = 1; // 1-indexed

        while (!q.isEmpty())
        {
            Node *temp = q.pop();
            output[i++] = temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    void preorder(Node *node) // dfs preorder
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node) // dfs inorder
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node *node) // dfs postorder
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;

        int lh = height(node->left);
        int rh = height(node->right);
        return max(lh, rh) + 1;
    }

    void printlevel(Node *node, int level)
    {
        if (node == nullptr)
            return;

        if (level == 1)
        {
            cout << node->data << " ";
        }
        else
        {
            printlevel(node->left, level - 1);
            printlevel(node->right, level - 1);
        }
    }

    void BFS()
    {
        int h = height(root);
        for (int i = 1; i <= h; i++)
        {
            printlevel(root, i);
        }
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    cout << "BFS Traversal: ";
    tree.BFS();
    cout << endl;

    cout << "Preorder DFS: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Inorder DFS: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Postorder DFS: ";
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}
