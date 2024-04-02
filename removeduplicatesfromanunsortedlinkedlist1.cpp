#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);

    tail->next=temp;

    tail=temp;
}

void Print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* removeDuplicates(Node* &head){
    Node* curr=head;
    Node* prev=NULL;

    unordered_map<int,bool> visited;

    while(curr!=NULL){
        int val=curr->data;
        if(visited[val]){
            prev->next=curr->next;
            delete curr;
            curr=prev->next;
        }
        else{
            visited[val]=true;
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

int main(){
    Node* Node1=new Node(4);

    Node* tail=Node1;
    Node* head=Node1;

    insertAtTail(tail,5);

    insertAtTail(tail,6);

    insertAtTail(tail,4);

    insertAtTail(tail,7);

    insertAtTail(tail,3);

    insertAtTail(tail,4);

    insertAtTail(tail,1);

    insertAtTail(tail,9);

    insertAtTail(tail,4);

    insertAtTail(tail,7);

    insertAtTail(tail,4);

    cout<<"Original Linked List"<<endl;
    Print(head);

    cout<<"Linked List after removing duplicate elements"<<endl;
    Node* newHead=removeDuplicates(head);
    Print(newHead);

    return 0;
}