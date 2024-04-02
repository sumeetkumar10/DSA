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

int leftHeight(Node* root){
    if(!root){
        return 0;
    }

    int count=0;
    while(root){
        count++;
        root=root->left;
    }
    return count;
}

int rightHeight(Node* root){
    if(!root){
        return 0;
    }

    int count=0;
    while(root){
        count++;
        root=root->right;
    }
    return count;
}

int countNodes(Node* root){
    if(!root){
        return 0;
    }

    int lh=leftHeight(root);
    int rh=rightHeight(root);

    if(lh==rh){
        return (1<<lh)-1;                         //(2^lh)-1
    }
    else{
        return (1+countNodes(root->left)+countNodes(root->right));
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"Number of nodes in Complete Binary Tree is "<<countNodes(root)<<endl;

    return 0;
}