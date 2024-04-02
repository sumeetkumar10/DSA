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

vector<int> mergeTwoSortedArrays(vector<int>& a,vector<int>& b){
    int n=a.size(),m=b.size();

    vector<int> ans(n+m);

    int i=0,j=0,k=0;

    while(i<n && j<m){
        if(a[i]<b[j]){
            ans[k++]=a[i++];
        }
        else{
            ans[k++]=b[j++];
        }
    }
    while(i<n){
        ans[k++]=a[i++];
    }
    while(j<m){
        ans[k++]=b[j++];
    }
    return ans;
}

vector<int> mergeTwoBSTs(Node* root1,Node* root2){
    vector<int> BST1,BST2;

    inorder(root1,BST1);
    inorder(root2,BST2);

    return mergeTwoSortedArrays(BST1,BST2);
}

int main(){
    Node* root1=new Node(16);
    Node* root2=new Node(21);

    takeInput(root1);
    takeInput(root2);

    vector<int> ans=mergeTwoBSTs(root1,root2);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}