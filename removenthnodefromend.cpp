#include<iostream>
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

Node* removeNthNodeFromEnd(Node* &head,int n){
    Node* fast=head;
    Node* slow=head;

    for(int i=0;i<n;i++){
        fast=fast->next;
    }

    if(fast==NULL){
        return head->next;
    }

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}

int main(){
    Node* Node1=new Node(24);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,9);

    insertAtTail(tail,15);

    insertAtTail(tail,18);

    insertAtTail(tail,12);

    insertAtTail(tail,6);

    insertAtTail(tail,3);

    insertAtTail(tail,27);

    insertAtTail(tail,96);

    insertAtTail(tail,63);

    insertAtTail(tail,48);

    insertAtTail(tail,39);

    insertAtTail(tail,18);

    Print(head);

    int n=3;

    Node* newList=removeNthNodeFromEnd(head,n);
    Print(newList);

    return 0;
}