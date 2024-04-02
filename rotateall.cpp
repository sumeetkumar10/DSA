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

Node* rotateLeft(Node* &head,int k){
    if(head==NULL && head->next==NULL){
        return head;
    }

    Node* curr=head,* next=NULL;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=head;
    curr=head;

    int count=1;
    while(curr!=NULL && count<k){
        count++;
        curr=curr->next;
    }
    next=curr->next;
    curr->next=NULL;
    return next;
}

int main(){
    Node* Node1=new Node(54);

    Node* tail=Node1;
    Node* head=Node1;

    insertAtTail(tail,72);

    insertAtTail(tail,36);

    insertAtTail(tail,96);

    insertAtTail(tail,18);

    insertAtTail(tail,24);

    Print(head);

    int k=2;
    Node* newLL=rotateLeft(head,k);

    Print(newLL);
    
    return 0;
}