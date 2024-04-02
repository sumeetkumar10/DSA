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
        insertIntoBST(root,data);
        cin>>data;
    }
}

pair<int,int> predecessorSuccessor(Node* root,int key){
    Node* temp=root;
    int pred=-1;
    int succ=-1;

// find the key
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }

    Node* leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }

    Node* rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}

int main(){
    Node* root=new Node(18);

    takeInput(root);

    int key;
    cout<<"Enter the value of key"<<endl;
    cin>>key;

    pair<int,int> ans=predecessorSuccessor(root,key);

    cout<<"The Inorder predecessor of "<<key<<" is "<<ans.first<<endl;
    cout<<"The Inorder successor of "<<key<<" is "<<ans.second<<endl;

    return 0;
}