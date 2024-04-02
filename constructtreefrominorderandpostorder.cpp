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

int findPosition(int in[],int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[],int post[],int& index,int inorderstart,int inorderend,int n){
    if(index<0 || inorderstart>inorderend){
        return NULL;
    }

    int element=post[index--];
    Node* root=new Node(element);
    int position=findPosition(in,element,n);

    root->right=solve(in,post,index,position+1,inorderend,n);
    root->left=solve(in,post,index,inorderstart,position-1,n);

    return root;
}

Node* buildBinaryTree(int in[],int post[],int n){
    int postorderindex=n-1;
    Node* ans=solve(in,post,postorderindex,0,n-1,n);
    return ans;
}

void printPreorder(Node* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    int in[5]={9,3,15,20,7};
    int post[5]={9,15,7,20,3};

    Node* ans=buildBinaryTree(in,post,5);

    printPreorder(ans);

    return 0;
}