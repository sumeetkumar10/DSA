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
    cout<<"Enter the data "<<endl;
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}

int traverse(Node* root,int target,int& ret){
    if(root==NULL){
        return 0;
    }

    if(root->data==target){
        ret=max(ret,height(root->right));
        ret=max(ret,height(root->left));
        return 1;
    }

    int val=traverse(root->left,target,ret);

    if(val){
        ret=max(ret,val+height(root->right));
        return val+1;
    }

    val=traverse(root->right,target,ret);

    if(val){
        ret=max(ret,val+height(root->left));
        return val+1;
    }
    return 0;
}

int minimumTimeToBurnTree(Node* root,int target){
    int ret=0;
    traverse(root,target,ret);
    return ret;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int target;
    cout<<"Enter the target"<<endl;
    cin>>target;

    cout<<"Minimum time = "<<minimumTimeToBurnTree(root,target);

    return 0;
}