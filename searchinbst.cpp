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

bool isPresentInBST(Node* root,int key){
    if(root==NULL){
        return false;
    }

    if(root->data==key){
        return true;
    }

    if(root->data>key){
        return isPresentInBST(root->left,key);
    }
    else{
        return isPresentInBST(root->right,key);
    }
}

int main(){
    Node* root=new Node(10);

    cout<<"Enter the data to create BST"<<endl;
    takeInput(root);

    int key;
    cout<<"Enter the data to search for"<<endl;
    cin>>key;

    if(isPresentInBST(root,key)){
        cout<<key<<" is present in the Binary Search Tree."<<endl;
    }
    else{
        cout<<key<<" is not present in the Binary Search Tree."<<endl;
    }
    
    return 0;
}