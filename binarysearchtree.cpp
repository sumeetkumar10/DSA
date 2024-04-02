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

Node* insertIntoBST(Node* &root,int data){
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

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
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

void inorder(Node* root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(Node* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
            root->left=NULL;
            delete root;
            root=temp;
            return temp;
        }

        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            root->right=NULL;
            delete root;
            root=temp;
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
    Node* root=new Node(18);

    cout<<"Enter the data for creating BST"<<endl;
    takeInput(root);

    cout<<"Level Order Traversal of the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal of the BST is "<<endl;
    inorder(root);

    cout<<endl;

    cout<<"Postorder Traversal of the BST is "<<endl;
    postorder(root);

    cout<<endl;

    cout<<"Preorder Traversal of the BST is "<<endl;
    preorder(root);

    cout<<endl;

    int val;
    cout<<"Enter the value to delete"<<endl;
    cin>>val;

    Node* deleteNode=deleteFromBST(root,val);

    levelOrderTraversal(deleteNode);

    return 0;
}