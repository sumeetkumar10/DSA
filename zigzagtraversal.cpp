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

vector<int> zigzagTreeTraversal(Node* root){
    vector<int> result;

    if(root==NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight=true;

    while(!q.empty()){
        int size=q.size();

        vector<int> ans(size);

        for(int i=0;i<size;i++){
            Node* frontNode=q.front();
            q.pop();

            int index=leftToRight?i:size-i-1;
            ans[index]=frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        leftToRight=!leftToRight;

        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> v=zigzagTreeTraversal(root);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}