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

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
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

pair<int,int> diameterOfBTFast(Node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> leftAns=diameterOfBTFast(root->left);
    pair<int,int> rightAns=diameterOfBTFast(root->right);

    int op1=leftAns.first;
    int op2=rightAns.first;
    int op3=leftAns.second+rightAns.second+1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(leftAns.second,rightAns.second)+1;

    return ans;
}

int diameterOfBT(Node* root){
    return diameterOfBTFast(root).first;
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

pair<bool,int> isBalancedBTFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> leftAns=isBalancedBTFast(root->left);
    pair<bool,int> rightAns=isBalancedBTFast(root->right);

    bool isLeftBalancedBT=leftAns.first;
    bool isRightBalancedBT=rightAns.first;
    bool difference=abs(leftAns.second-rightAns.second)<=1;

    pair<bool,int> ans;
    ans.second=max(leftAns.second,rightAns.second)+1;

    if(isLeftBalancedBT && isRightBalancedBT && difference){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isBalancedBT(Node* root){
    return isBalancedBTFast(root).first;
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

    bool value=root->data==leftSum+rightSum;

    pair<bool,int> ans;

    if(isLeftSumTree && isRightSumTree && value){
        ans.first=true;
        ans.second=root->data+leftSum+rightSum;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
}

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if(root1==NULL && root2!=NULL){
        return false;
    }

    if(root1!=NULL && root2==NULL){
        return false;
    }

    bool isLeftIdentical=isIdentical(root1->left,root2->left);
    bool isRightIdentical=isIdentical(root1->right,root2->right);

    bool value=root1->data==root2->data;
}

vector<int> zigzagTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    vector<int> result;
    if(root==NULL){
        return result;
    }

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

vector<int> verticalTraversal(Node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;

    vector<int> ans;

    if(root==NULL){
        return ans;
    }

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

void traverseLeft(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        return ;
    }

    ans.push_back(root->data);

    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}

void traverseRight(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        return ;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseLeft(root->left,ans);
    }
    ans.push_back(root->data);
}

void traverseLeaf(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return ;
    }

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    ans.push_back(root->data);

    traverseLeft(root->left,ans);
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    traverseRight(root->right,ans);
    return ans;
}

void solve(Node* root,vector<int> &ans,int level){
    if(root==NULL){
        return ;
    }

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

void solveRight(Node* root,vector<int>& ans,int level){
    if(root==NULL){
        return ;
    }

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    solveRight(root->right,ans,level+1);
    solveRight(root->left,ans,level+1);
}

vector<int> rightView(Node* root){
    vector<int> ans;
    solveRight(root,ans,0);
    return ans;
}

vector<int> bottomView(Node* root){
    map<int,int> bottomNode;
    queue<pair<Node*,int>> q;

    q.push(make_pair(root,0));

    vector<int> ans;

    if(root==NULL){
        return ans;
    }

    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;
        int horizDist=temp.second;

        bottomNode[horizDist]=frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,horizDist-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,horizDist+1));
        }
    }
    for(auto i:bottomNode){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The height of the Binary Tree is "<<height(root)<<endl;

    cout<<"The diameter of the Binary Tree is "<<diameter(root)<<endl;

    cout<<"Diameter of Binary Tree = "<<diameterOfBT(root)<<endl;

    if(isBalancedTree(root)){
        cout<<"The Binary Tree is balanced."<<endl;
    }
    else{
        cout<<"The Binary Tree is not balanced."<<endl;
    }

    if(isBalancedBT(root)){
        cout<<"Yes it is balanced."<<endl;
    }
    else{
        cout<<"No it is not balanced."<<endl;
    }

    if(isSumTree(root)){
        cout<<"The Binary Tree is a sum tree."<<endl;
    }
    else{
        cout<<"The Binary Tree is not a sum tree."<<endl;
    }

    vector<int> v=zigzagTraversal(root);

    cout<<"Zig Zag traversal of the Binary Tree is "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> vertical=verticalTraversal(root);

    cout<<"The Vertical traversal of the Binary Tree is "<<endl;
    for(int i=0;i<vertical.size();i++){
        cout<<vertical[i]<<" ";
    }
    cout<<endl;

    vector<int> top=topView(root);

    cout<<"Top View is "<<endl;
    for(int i=0;i<top.size();i++){
        cout<<top[i]<<" ";
    }
    cout<<endl;

    vector<int> boundary=boundaryTraversal(root);

    cout<<"The Boundary traversal of the Binary Tree is "<<endl;
    for(int i=0;i<boundary.size();i++){
        cout<<boundary[i]<<" ";
    }
    cout<<endl;

    vector<int> leftV=leftView(root);

    cout<<"The Left view of the Binary Tree is "<<endl;
    for(int i=0;i<leftV.size();i++){
        cout<<leftV[i]<<" ";
    }
    cout<<endl;

    vector<int> rightV=rightView(root);

    cout<<"The Right view of the Binary Tree is "<<endl;
    for(int i=0;i<rightV.size();i++){
        cout<<rightV[i]<<" ";
    }
    cout<<endl;

    vector<int> bottom=bottomView(root);

    cout<<"The Bottom view of the Binary Tree is "<<endl;
    for(int i=0;i<bottom.size();i++){
        cout<<bottom[i]<<" ";
    }
    cout<<endl;

    return 0;
}