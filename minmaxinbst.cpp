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

Node* insertIntoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data>root->data){
        root->right=insertIntoBST(root->right,data);
    }
    else{
        root->left=insertIntoBST(root->left,data);
    }
    return root;
}

void takeInput(Node* root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

Node* minVal(Node* root){
    Node* temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp=root;

    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

int main(){
    Node* root=new Node(18);

    cout<<"Enter the data to create BST"<<endl;
    takeInput(root);

    int max=maxVal(root)->data;
    int min=minVal(root)->data;

    cout<<"The maximum value in the Binary Search tree is "<<max<<endl;
    cout<<"The minimum value in the Binary Search Tree is "<<min<<endl;
    
    return 0;
}