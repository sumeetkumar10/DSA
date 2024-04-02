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

pair<int,int> solve(Node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> leftAns=solve(root->left);
    pair<int,int> rightAns=solve(root->right);

    pair<int,int> res;

    res.first=root->data+leftAns.second+rightAns.second;
    res.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);

    return res;
}

int getMax(Node* root){
    pair<int,int> ans=solve(root);
    return max(ans.first,ans.second);
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int k;
    cout<<"Enter the value for k"<<endl;
    cin>>k;

    cout<<"The maximum sum of non-adjacent nodes is "<<getMax(root)<<endl;

    return 0;
}