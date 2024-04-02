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
    root->right=buildTree(root->right);
    return root;
}

int solve(Node* root,int& maxi){
    if(root==NULL){
        return 0;
    }

    int left=max(0,solve(root->left,maxi));
    int right=max(0,solve(root->right,maxi));
    maxi=max(maxi,left+right+root->data);
    return max(left,right)+root->data;
}

int maxPathSum(Node* root){
    int maxi=INT_MIN;
    solve(root,maxi);
    return maxi;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The maximum path bsum in the Binary Tree is "<<maxPathSum(root)<<endl;

    return 0;
}