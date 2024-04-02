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

int solve(Node* root,int& i,int k){
    if(root==NULL){
        return -1;
    }

    int left=solve(root->left,i,k);

    if(left!=-1){
        return left;
    }

    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);
}

int kthSmallest(Node* root,int k){
    int ans=0;
    int res=solve(root,ans,k);
    return res;
}

int main(){
    Node* root=new Node(18);

    takeInput(root);

    int k;
    cout<<"Enter k"<<endl;
    cin>>k;

    cout<<k <<" th smallest element in the BST is "<<kthSmallest(root,k);

    return 0;
}