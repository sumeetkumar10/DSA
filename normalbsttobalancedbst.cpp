#include<iostream>
#include<queue>
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
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

void inorder(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

Node* inorderToBST(int start,int end,vector<int>& ans){
    if(start>end){
        return NULL;
    }

    int mid=start+(end-start)/2;

    Node* root=new Node(ans[mid]);

    root->left=inorderToBST(start,mid-1,ans);
    root->right=inorderToBST(mid+1,end,ans);

    return root;
}

Node* balancedBST(Node* root){
    vector<int> ans;
    inorder(root,ans);
    return inorderToBST(0,ans.size()-1,ans);
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

int main(){
    Node* root=new Node(18);

    takeInput(root);

    cout<<"Normal BST:- "<<endl;

    levelOrderTraversal(root);

    Node* ans=balancedBST(root);

    cout<<"Balanced BST:- "<<endl;

    levelOrderTraversal(ans);

    return 0;
}