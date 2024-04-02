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

Node* lca(Node* &root,int first,int second){
    if(root==NULL){
        return NULL;
    }

    if(root->data==first || root->data==second){
        return root;
    }

    Node* leftAns=lca(root->left,first,second);
    Node* rightAns=lca(root->right,first,second);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    return (leftAns==NULL) ? rightAns : leftAns;
}

int getDist(Node* root,int d){
    if(root==NULL){
        return -1;
    }

    if(root->data==d){
        return 0;
    }

    int leftAns=getDist(root->left,d);
    int rightAns=getDist(root->right,d);

    if(leftAns==-1 && rightAns==-1){
        return -1;
    }
    else if(leftAns==-1){
        return rightAns+1;
    }
    else if(rightAns==-1){
        return leftAns+1;
    }
}

int minDist(Node* root,int first,int second){
    int distA=getDist(root,first);
    int distB=getDist(root,second);

    return distA+distB;
}

int findDist(Node* root,int first,int second){
    Node* loca=lca(root,first,second);
    int dist=minDist(loca,first,second);
    return dist;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int first;
    cout<<"Enter the value of the first node"<<endl;
    cin>>first;

    int second;
    cout<<"Enter the value of the second node"<<endl;
    cin>>second;

    cout<<"The distance between "<<first<<" and "<<second<<" node is "<<findDist(root,first,second)<<endl;

    return 0;
}