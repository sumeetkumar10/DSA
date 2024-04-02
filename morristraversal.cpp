#include<iostream>
#include<vector>
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

vector<int> getInorder(Node* root){
    vector<int> inorder;
    Node* curr=root;

    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorder(Node* root){
    vector<int> preorder;
    Node* curr=root;

    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                preorder.push_back(curr->data);
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> v=getInorder(root);

    cout<<"Inorder traversal of the Binary Tree is "<<endl;

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    vector<int> v1=getPreorder(root);

    cout<<endl<<"Preorder traversal of the Binary Tree is "<<endl;

    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }

    return 0;
}