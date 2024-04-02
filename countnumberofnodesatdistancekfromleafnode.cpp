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

bool check(Node* root,int k){
    if(root==NULL){
        return false;
    }

    if(k==0 && root->left==NULL && root->right==NULL){
        return true;
    }

    return (check(root->left,k-1) || check(root->right,k-1));
}

int solve(Node* root,int k){
    if(root==NULL){
        return 0;
    }

    int ans=check(root,k)+solve(root->left,k)+solve(root->right,k);
    return ans;
}

int countNodesAtDistanceK(Node* root,int k){
    return solve(root,k);
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int k;
    cout<<"Enter the data of k"<<endl;
    cin>>k;

    cout<<"The number of unique nodes at a distance of "<<k<<" from the leaf node is "<<countNodesAtDistanceK(root,k)<<endl;

    return 0;
}