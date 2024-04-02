#include<iostream>
#include<vector>
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

void traverseLeft(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        return ;
    }

    ans.push_back(root->data);

    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}

void traverseRight(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        return ;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}

void traverseLeaf(Node* root,vector<int> &ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return ;
    }

    traverseLeaf(root->left,ans);
    
    traverseLeaf(root->right,ans);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    ans.push_back(root->data);

    traverseLeft(root->left,ans);

    traverseLeaf(root->left,ans);

    traverseLeaf(root->right,ans);

    traverseRight(root->right,ans);

    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> v=boundaryTraversal(root);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}