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

bool isTwoSum(Node* root,int target){
    vector<int> inorderVal;
    inorder(root,inorderVal);

    int i=0,j=inorderVal.size()-1;

    while(i<j){
        int sum=inorderVal[i]+inorderVal[j];

        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    Node* root=new Node(18);

    takeInput(root);

    int target;
    cout<<"Enter the value of target"<<endl;
    cin>>target;

    if(isTwoSum(root,target)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}