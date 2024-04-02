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

bool getPath(Node* root,vector<int>& ans,int x){
    if(root==NULL){
        return false;
    }

    ans.push_back(root->data);

    if(root->data==x){
        return true;
    }

    if(getPath(root->left,ans,x) || getPath(root->right,ans,x)){
        return true;
    }
    ans.pop_back();

    return false;
}

vector<int> getRootToNodePath(Node* A,int B){
    vector<int> ans;
    if(A==NULL){
        return ans;
    }

    getPath(A,ans,B);
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int x;
    cout<<"Enter the node"<<endl;
    cin>>x;

    vector<int> v=getRootToNodePath(root,x);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}