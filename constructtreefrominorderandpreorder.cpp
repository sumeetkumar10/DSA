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

int findPosition(int in[],int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[],int pre[],int& index,int inorderStart,int inorderEnd,int n){
    if(index>=n || inorderStart>inorderEnd){
        return NULL;
    }

    int element=pre[index++];
    Node* root=new Node(element);
    int position=findPosition(in,element,n);

    root->left=solve(in,pre,index,inorderStart,position-1,n);
    root->right=solve(in,pre,index,position+1,inorderEnd,n);

    return root;
}

Node* buildBinaryTree(int in[],int pre[],int n){
    int preOrderIndex=0;
    Node* ans=solve(in,pre,preOrderIndex,0,n-1,n);
    return ans;
}

void printPostorder(Node* node)
{
    if (node == NULL){
        return;
    }

    printPostorder(node->left);
    printPostorder(node->right);
    cout<<node->data<<" ";
}

int main(){
    int in[7]={7 ,3, 11, 1, 17, 3, 18};
    int pre[7]={1 ,3, 7, 11, 3, 17, 18};

    Node* res=buildBinaryTree(in,pre,7);
    printPostorder(res);

    return 0;
}