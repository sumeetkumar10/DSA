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
    cout << "Length of the Linked List is " << count;
}

int main(){
    node* node1=new node(87);

    node* head=node1;

    Print(head);

    insertAtHead(head,88);
    Print(head);

    insertAtHead(head,89);
    Print(head);

    insertAtHead(head,99);
    Print(head);

    insertAtHead(head,108);
    Print(head);

    insertAtHead(head,1225);
    Print(head);

    getLength(head);

    return 0;
}