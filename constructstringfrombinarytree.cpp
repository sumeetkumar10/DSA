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

string tree2str(Node* root){
    string ans=to_string(root->data);

    if(root->left!=NULL){
        ans+="("+tree2str(root->left)+")";
    }
    if(root->right!=NULL){
        if(root->left==NULL){
            ans+="()";
        }
        ans+="("+tree2str(root->right)+")";
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The string representation of the Binary Tree is "<<tree2str(root)<<endl;

    return 0;
}