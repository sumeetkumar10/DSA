#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting in the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

bool isIdenticalTrees(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
        return true;

    if(root1==NULL && root2!=NULL)
        return false;

    if(root1!=NULL && root2==NULL)
        return false;

    bool left=isIdenticalTrees(root1->left,root2->left);
    bool right=isIdenticalTrees(root1->right,root2->right);

    bool value=root1->data==root2->data;

    if(left && right && value)
        return true;
    else
        return false;
}

int main(){
    Node* root1=NULL;
    Node* root2=NULL;

    root1=buildTree(root1);
    root2=buildTree(root2);

    if(isIdenticalTrees(root1,root2))
        cout<<"The two Binary Trees are identical."<<endl;
    else
        cout<<"The two Binary Trees are not identical."<<endl;

    return 0;
}