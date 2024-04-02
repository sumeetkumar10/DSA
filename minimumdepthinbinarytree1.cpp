#include<iostream>
#include<queue>
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
    root->right=buildTree(root->left);
    return root;
}

int minimumDepth(Node* root){
    if(root==NULL){
        return 0;
    }

    int depth=1;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int currLevelSize=q.size();

        while(currLevelSize--){
            Node* curr=q.front();
            q.pop();

            if(curr->left==NULL && curr->right==NULL){
                return depth;
            }

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(root->right);
            }
        }
        depth++;
    }
    return depth;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The minimum depth in the Binary Tree is "<<minimumDepth(root)<<endl;

    return 0;
}