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

int findMax(Node *root)
{
    if (root == NULL){
        return INT_MIN;
    }

    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int findMin(struct Node *root)
{
    if (root == NULL){
        return INT_MAX;
    }
    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    cout<<findMin(root)<<" "<<findMax(root)<<endl;

    return 0;
}