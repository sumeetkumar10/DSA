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

pair<int,int> solve(Node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> left=solve(root->left);
    pair<int,int> right=solve(root->right);

    int a=left.first+right.first+root->data;
    int b=left.second+right.second+abs(left.first-right.first);

    pair<int,int> ans=make_pair(a,b);
    return ans;
}

int tiltBT(Node* root){
    pair<int,int> ans;
    return solve(root).second;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The tilt of the Binary Tree is "<<tiltBT(root)<<endl;

    return 0;
}