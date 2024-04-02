#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node *root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

int findCeil(Node *root, int key)
{
    int ceil = -1;

    while (root != NULL)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int main()
{
    Node *root = new Node(18);

    takeInput(root);

    int key;
    cout << "Enter the value of key" << endl;
    cin >> key;

    cout << "The ceil of " << key << " in the BST is " << findCeil(root, key) << endl;

    return 0;
}