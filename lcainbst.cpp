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

Node* LCA(Node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }

    if(root->data<p && root->data<q){
        return LCA(root->right,p,q);
    }
    if(root->data>p && root->data>q)
        return LCA(root->left,p,q);

    return root;
}

int main(){
    Node* root=new Node(18);

    takeInput(root);

    int p;
    cout<<"Enter the value of first node"<<endl;
    cin>>p;

    int q;
    cout<<"Enter the value of second node"<<endl;
    cin>>q;

    Node* ans=LCA(root,p,q);

    cout<<"The LCA of "<<p<<" and "<<q<<" is "<<ans->data<<endl;

    return 0;
}