#include <iostream>
#include<map>
#include<queue>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in the left node " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in the right node " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void markParents(Node* root,map<Node*,Node*>& mp,int target){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        if(curr->left){
            mp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            mp[curr->right]=curr;
            q.push(curr->right);
        }
    }
}

Node* tar(Node* root,int target){
    queue<Node*> q;
    q.push(root);

    Node* ans;

    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        if(curr->data==target){
            ans=curr;
            break;
        }
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    return ans;
}

vector<int> nodesAtDistanceK(Node* root,int target,int k){
    map<Node*,Node*> parent_track;
    markParents(root,parent_track,target);
    Node* t=tar(root,target);
    queue<Node*> q;
    q.push(t);
    map<Node*,bool> visited;
    visited[t]=true;
    int curr_level=0;

    while(!q.empty()){
        if(curr_level++==k){
            break;
        }
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* curr=q.front();
            q.pop();

            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parent_track[curr] && !visited[parent_track[curr]]){
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
            }
        }
    }
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        ans.push_back(curr->data);
    }
    return ans;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    int target;
    cout<<"Enter the value of target"<<endl;
    cin>>target;

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    vector<int> v=nodesAtDistanceK(root,target,k);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}