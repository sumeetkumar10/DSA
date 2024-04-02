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

    cout<<"Enter the value for inserting in the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

bool isChildSum(Node* root){
    if(root==NULL){
        return true;
    }

    if(root->left==NULL && root->right==NULL){
        return true;
    }

    int sum=0;
    if(root->left){
        sum+=root->left->data;
    }
    if(root->right){
        sum+=root->right->data;
    }
    if(root->data!=sum){
        return false;
    }

    return (isChildSum(root->left) && isChildSum(root->right));
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(isChildSum(root)){
        cout<<"Yes it follows children sum parent property."<<endl;
    }
    else{
        cout<<"No it does not follow children sum parent property."<<endl;
    }

    return 0;
}