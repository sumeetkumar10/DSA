#include<iostream>
#include<vector>
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
    root->right=buildTree(root->right);
    return root;
}

vector<int> diagonalTraversal(Node* root){
    queue<Node*> q;
    vector<int> ans;
    q.push(root);

    if(root==NULL){
        return ans;
    }

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        
        while(temp!=NULL){
            if(temp->left){
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> v=diagonalTraversal(root);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}