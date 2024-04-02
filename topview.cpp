#include<iostream>
#include<map>
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

Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

vector<int> topView(Node* root){
    map<int,int> topNode;
    queue<pair<Node*,int>> q;

    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;

        int horizDist=temp.second;

        if(topNode.find(horizDist)==topNode.end()){
            topNode[horizDist]=frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,horizDist-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,horizDist+1));
        }
    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> v=topView(root);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}