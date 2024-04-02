#include<iostream>
#include<vector>
#include<map>
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    return max(leftHeight,rightHeight)+1;
}

pair<int,int> diameterFast(Node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> leftAns=diameterFast(root->left);
    pair<int,int> rightAns=diameterFast(root->right);

    int op1=leftAns.first;
    int op2=rightAns.first;
    int op3=leftAns.second+rightAns.second+1;

    pair<int,int> ans;
    ans.second=max(leftAns.second,rightAns.second)+1;

    ans.first=max(op1,max(op2,op3));
    return ans;

}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }

    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;

    return max(op1,max(op2,op3));
}

int diameterOfBT(Node* root){
    return diameterFast(root).first;
}

pair<bool,int> isBalancedTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> leftAns=isBalancedTreeFast(root->left);
    pair<bool,int> rightAns=isBalancedTreeFast(root->right);

    bool isLeftTreeBalanced=leftAns.first;
    bool isRightTreeBalanced=rightAns.first;

    bool diff=abs(leftAns.second-rightAns.second)<=1;

    pair<bool,int> ans;
    ans.second=max(leftAns.second,rightAns.second)+1;

    if(isLeftTreeBalanced && isRightTreeBalanced && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isBalancedTree(Node* root){
    if(root==NULL){
        return true;
    }

    bool isLeftBalanced=isBalancedTree(root->left);
    bool isRightBalanced=isBalancedTree(root->right);

    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(isLeftBalanced && isRightBalanced && diff){
        return true;
    }
    else{
        return false;
    }
}

bool isBTBalanced(Node* root){
    return isBalancedTreeFast(root).first;
}

pair<bool,int> isSumTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns=isSumTreeFast(root->left);
    pair<bool,int> rightAns=isSumTreeFast(root->right);

    bool isLeftSumTree=leftAns.first;
    bool isRightSumTree=rightAns.first;

    int leftSum=leftAns.second;
    int rightSum=rightAns.second;

    bool val=root->data==leftSum+rightSum;

    pair<bool,int> ans;
    
    if(isLeftSumTree && isRightSumTree && val){
        ans.first=true;
        ans.second=root->data+leftSum+rightSum;
        // ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
}

vector<int> verticalTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<Node*,pair<int,int>> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;

        int horizDist=temp.second.first;
        int level=temp.second.second;

        nodes[horizDist][level].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(horizDist-1,level+1)));
        }
        if(frontNode->right){
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

    cout<<"The height of the Binary Tree is "<<height(root)<<endl;

    // cout<<"The diameter of the Binary Tree is "<<diameter(root)<<endl;

    cout<<"The diameter of the Binary Tree is "<<diameterOfBT(root)<<endl;

    // if(isBalancedTree(root)){
    //     cout<<"The Binary tree is Balanced."<<endl;
    // }
    // else{
    //     cout<<"The Binary Tree is Not Balanced."<<endl;
    // }

    if(isBTBalanced(root)){
        cout<<"The Binary tree is Balanced."<<endl;
    }
    else{
        cout<<"The Binary Tree is Not Balanced."<<endl;
    }

    if(isSumTree(root)){
        cout<<"The Binary Tree is a Sum Tree."<<endl;
    }
    else{
        cout<<"The Binary Tree is not a Sum Tree."<<endl;
    }

    vector<int> verticalAns=verticalTraversal(root);

    for(int i=0;i<verticalAns.size();i++){
        cout<<verticalAns[i]<<" ";
    }
    cout<<endl;

    return 0;
}