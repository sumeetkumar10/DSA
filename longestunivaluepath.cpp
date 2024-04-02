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
    cout<<"Enter the data for inserting in the left of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

int solve(Node* root,int& ans){
    if(root==NULL){
        return 0;
    }

    int leftMax=0,rightMax=0;

    int left=solve(root->left,ans);
    int right=solve(root->right,ans);

    if(root->left!=NULL && root->left->data==root->data){
        leftMax=left;
    }
    if(root->right!=NULL && root->right->data==root->data){
        rightMax=right;
    }

    ans=max(ans,leftMax+rightMax);

    return 1+max(leftMax,rightMax);
}

int longestUnivaluePath(Node* root){
    int ans=0;
    solve(root,ans);
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The Longest Univalue Path in the binary tree is "<<longestUnivaluePath(root)<<endl;

    return 0;
}