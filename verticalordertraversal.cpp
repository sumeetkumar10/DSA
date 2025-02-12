#include<iostream>
#include<map>
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

vector<int> verticalOrder(Node* root){
    map<int,map<int,vector<int>>> nodes;

    //for level order traversal
    queue<pair<Node*,pair<int,int>>> q;

    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<Node*,pair<int,int>> temp=q.front();
        //              horizDist,level
        q.pop();

        Node* frontNode=temp.first;

        int horizDist=temp.second.first;
        int level=temp.second.second;

        nodes[horizDist][level].push_back(frontNode->data);

        if(frontNode->left!=NULL){
            q.push(make_pair(frontNode->left,make_pair(horizDist-1,level+1)));
        }
        if(frontNode->right!=NULL){
            q.push(make_pair(frontNode->right,make_pair(horizDist+1,level+1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> v=verticalOrder(root);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}