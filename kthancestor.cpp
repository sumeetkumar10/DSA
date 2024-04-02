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

Node* solve(Node* root,int& k,int node){
    if(root==NULL){
        return NULL;
    }

    if(root->data==node){
        return root;
    }

    Node* leftAns=solve(root->left,k,node);
    Node* rightAns=solve(root->right,k,node);

    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node* root,int k,int node){
    Node* ans=solve(root,k,node);

    if(ans==NULL || ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int k;
    cout<<"Enter the value for k"<<endl;
    cin>>k;

    int node;
    cout<<"Enter the value for node"<<endl;
    cin>>node;

    cout<<k<<" th ancestor of "<<node<<" is "<<kthAncestor(root,k,node)<<endl;

    return 0;
}