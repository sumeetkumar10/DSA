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

Node* deleteMiddle(Node* &head){
    if(head==NULL){
        return head;
    }

    if(head->next==NULL){
        return head;
    }

    Node* prev=NULL;
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* forward=slow->next;
    prev->next=forward;
    return head;
}

int main(){
    Node* Node1=new Node(6);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,5);

    insertAtTail(tail,9);

    insertAtTail(tail,9801);

    insertAtTail(tail,961);

    insertAtTail(tail,144);

    insertAtTail(tail,225);

    insertAtTail(tail,576);

    cout<<"The original Linked List is "<<endl;
    Print(head);

    Node* newNode=deleteMiddle(head);
    cout<<"The Linked List after deleting middle element is "<<endl;
    Print(newNode);

    return 0;
}