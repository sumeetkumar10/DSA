#include<iostream>
#include<climits>
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
    root->right=buildTree(root->left);
    return root;
}

int minimumDepth(Node* &root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return 1;
    }

    int l=INT_MAX;
    int r=INT_MAX;

    if(root->left!=NULL){
        l=minimumDepth(root->left);
    }
    if(root->right!=NULL){
        r=minimumDepth(root->right);
    }
    return min(l,r)+1;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The minimum depth of the binary tree is "<<minimumDepth(root)<<endl;

    return 0;
}