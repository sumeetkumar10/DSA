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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}

bool isBalancedTree(Node* root){
    if(root==NULL){
        return true;
    }

    bool left=isBalancedTree(root->left);
    bool right=isBalancedTree(root->right);

    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(isBalancedTree(root)){
        cout<<"Yes, the Binary Tree is Balanced."<<endl;
    }
    else{
        cout<<"No, the Binary Tree is not Balanced."<<endl;
    }

    return 0;
}