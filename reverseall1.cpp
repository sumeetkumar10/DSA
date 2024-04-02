#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data;
        this->next=NULL;
    }
};

void insertAtTail(node* &tail,int d){
    node* temp=new node(d);

    tail->next=temp;

    tail=temp;
}

void Print(node* &tail){
    node* temp=tail;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Reverse(node* &head,node* &curr,node* &previous){
    if(curr==NULL){
        head=previous;
        return ;
    }
    node* forward=curr->next;
    Reverse(head,forward,curr);
    curr->next=previous;
}

node* reverseLL(node* &head){
    node* previous=NULL;
    node* curr=head;
    Reverse(head,curr,previous);
    return head;
}

int main(){
    node* node1=new node(62);

    node* head=node1;
    node* tail=node1;

    insertAtTail(tail,31);

    insertAtTail(tail,65);

    insertAtTail(tail,97);

    insertAtTail(tail,95);

    insertAtTail(tail,52);

    insertAtTail(tail,82);

    insertAtTail(tail,23);

    insertAtTail(tail,37);

    cout<<"Original Linked List:"<<endl;

    Print(head);

    cout<<"Reversed Linked List:"<<endl;

    node* reversedLL=reverseLL(head);
    Print(reversedLL);

    return 0;
}