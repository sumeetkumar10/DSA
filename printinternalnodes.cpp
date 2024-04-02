#include <iostream>
#include <climits>
#include <queue>
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

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void printInternalNodes(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        bool isInternal = 0;

        if (curr->left)
        {
            isInternal = 1;
            q.push(curr->left);
        }
        if (curr->right)
        {
            isInternal = 1;

            q.push(curr->right);
        }
        if (isInternal)
            cout << curr->data << " ";
    }
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    printInternalNodes(root);

    return 0;
}