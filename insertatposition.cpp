#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(node* &head,int d){
    node* temp=new node(d);

    temp->next=head;

    head=temp;
}

void insertAtTail(node* &tail,int d){
    node* temp=new node(d);

    tail->next=temp;

    tail=temp;
}

void Print(node* &head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(node* &head){
    node* temp=head;

    int count=0;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<"The length of the linked list is "<<count<<endl;
}

void insertAtPosition(node* &head,int position,int d){
    if(position==1){
        insertAtHead(head,d);
        return ;
    }
    
    int count=1;
    node* temp=head;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    node* nodeToInsert=new node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

int main(){
    node* node1=new node(87);
    
    node* head=node1;
    node* tail=node1;

    Print(head);

    insertAtHead(head,56);
    Print(head);
    
    insertAtHead(head,168);
    Print(head);

    insertAtHead(head,78);
    Print(head);

    insertAtHead(head,84);
    Print(head);

    insertAtHead(head,24);
    Print(head);

    insertAtHead(head,36);
    Print(head);

    insertAtTail(tail,51);
    Print(head);

    insertAtTail(tail,85);
    Print(head);

    insertAtHead(head,-96);
    Print(head);

    insertAtTail(tail,18);
    Print(head);

    insertAtTail(tail,48);
    Print(head);

    insertAtTail(tail,99);
    Print(head);

    insertAtPosition(head,5,93);
    Print(head);

    insertAtPosition(head,9,52);
    Print(head);

    getLength(head);

    return 0;
}