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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* minVal(Node* root){
    Node* temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root,int val){
    if(root==NULL){
        return root;
    }

    if(root->data==val){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(val>root->data){
        root->right=deleteFromBST(root->right,val);
        return root;
    }
    else{
        root->left=deleteFromBST(root->left,val);
        return root;
    }
}

int main(){
    Node* root=new Node(10);

    takeInput(root);

    levelOrderTraversal(root);

    int key;
    cout<<"Enter the key to delete from the Binary Search Tree."<<endl;
    cin>>key;

    Node* ans=deleteFromBST(root,key);

    levelOrderTraversal(ans);

    return 0;
}