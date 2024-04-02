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
    cout<<"The Length Of The Linked List Is "<<count<<endl;
}

int main(){
    node* node1=new node(54);

    node* head=node1;
    node* tail=node1;

    Print(head);

    insertAtTail(tail,18);
    Print(head);

    insertAtTail(tail,66);
    Print(head);

    insertAtTail(tail,57);
    Print(head);

    insertAtTail(tail,72);
    Print(head);

    insertAtTail(tail,63);
    Print(head);

    insertAtTail(tail,48);
    Print(head);

    getLength(head);

    return 0;
}