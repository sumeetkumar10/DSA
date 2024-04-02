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
    root->left=buildTree(root->left);
    return root;
}

int sum=0;
int evenSumGrandparent(Node* root){
    if(root==NULL){
        return 0;
    }

    if(root->data%2==0){
        if(root->left){
            if(root->left->left) sum+=root->left->left->data;
            if(root->left->right) sum+=root->left->right->data;
        }
        if(root->right){
            if(root->right->left) sum+=root->right->left->data;
            if(root->right->right) sum+=root->right->right->data;
        }
    }
    evenSumGrandparent(root->left);
    evenSumGrandparent(root->right);

    return sum;
}


int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The sum of even sum grandparent is "<<evenSumGrandparent(root)<<endl;

    return 0;
}