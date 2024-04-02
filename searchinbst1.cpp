#include<iostream>
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
    cout<<"Enter the data"<<endl;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

bool searchInBST(Node* root,int x){
    Node* temp=root;
    
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}

int solve(Node* root,int& i,int k){
    if(root==NULL){
        return -1;
    }

    int left=solve(root->left,i,k);

    if(left!=-1){
        return left;
    }

    i++;
    if(i==k){
        return root->data;
    }
    solve(root->right,i,k);
}

int kthSmallest(Node* root,int k){
    int i=0;
    return solve(root,i,k);
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* minVal(Node* root){
    Node* temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

int main(){
    Node* root=new Node(10);

    takeInput(root);

    int x;
    cout<<"Enter the data to search"<<endl;
    cin>>x;

    if(searchInBST(root,x)){
        cout<<x<<" is present in the Binary Search Tree."<<endl;
    }
    else{
        cout<<x<<" is not present in the Binary Search Tree."<<endl;
    }
    
    int k;
    cin>>k;

    cout<<k<<" th smallest element in the Binary Search Tree is "<<kthSmallest(root,k)<<endl;

    levelOrderTraversal(root);

    Node* ans=minVal(root);

    cout<<"The Minimum Value in the Binary Search Tree is "<<ans->data<<endl;

    return 0;
}