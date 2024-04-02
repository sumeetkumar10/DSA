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

pair<bool,int> isSumTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns=isSumTreeFast(root->left);
    pair<bool,int> rightAns=isSumTreeFast(root->right);

    bool isLeftSumTree=leftAns.first;
    bool isRightSumTree=rightAns.first;

    int leftSum=leftAns.second;
    int rightSum=rightAns.second;

    bool condition=root->data==leftSum+rightSum;

    pair<bool,int> ans;
    
    if(isLeftSumTree && isRightSumTree && condition){
        ans.first=true;
        ans.second=root->data+leftSum+rightSum;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(isSumTree(root)){
        cout<<"Sum Tree exists."<<endl;
    }
    else{
        cout<<"Sum Tree does not exist."<<endl;
    }

    return 0;
}