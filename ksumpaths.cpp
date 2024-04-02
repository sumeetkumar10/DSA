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

    if(data==0){
        return NULL;
    }

    cout<<"Enter the data for inserting in the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void solve(Node* root,int& count,int k,vector<int>& path){
    if(root==NULL){
        return ;
    }

    //create a vector of path
    path.push_back(root->data);

    solve(root->left,count,k,path);
    solve(root->right,count,k,path);

    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();
}

int kPathSum(Node* root,int k){
    int count=0;
    vector<int> path;
    solve(root,count,k,path);
    return count;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    cout<<"K Path Sum = "<<kPathSum(root,k)<<endl;

    return 0;
}