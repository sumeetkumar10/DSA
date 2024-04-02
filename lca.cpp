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

Node* lca(Node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }

    if(root->data==p || root->data==q){
        return root;
    }

    Node* leftAns=lca(root->left,p,q);
    Node* rightAns=lca(root->right,p,q);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int p;
    cout<<"Enter the value for first node"<<endl;
    cin>>p;

    int q;
    cout<<"Enter the value for second node"<<endl;
    cin>>q;

    Node* ans=lca(root,p,q);

    cout<<"The lowest common ancestor of the Binary Tree is "<<ans->data<<endl;

    return 0;
}