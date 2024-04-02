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

Node* kReverse(Node* &head,int k){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    int count=0;

    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(next!=NULL){
        head->next=kReverse(next,k);
    }
    return prev;
}

int main(){
    Node* Node1=new Node(3);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,99);

    insertAtTail(tail,102);

    insertAtTail(tail,231);

    insertAtTail(tail,234);

    insertAtTail(tail,369);

    insertAtTail(tail,432);

    cout<<"The original Linked List is "<<endl;
    Print(head);

    int k=2;

    Node* newNode=kReverse(head,k);
    cout<<"Revesred Linked List is "<<endl;
    Print(newNode);

    return 0;
}