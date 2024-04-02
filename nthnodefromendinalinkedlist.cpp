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

int nthNodeFromEnd(node* &head,int n){
    node* temp=head;
    int len=0,i;

    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    
    if(len<n){
        return -1;
    }

    temp=head;

    for(i=1;i<len-n+1;i++){
        temp=temp->next;
    }
    return temp->data;
}

int main(){
    node* node1=new node(15);

    node* head=node1;
    node* tail=node1;

    insertAtTail(tail,56);

    insertAtTail(tail,95);
    
    insertAtTail(tail,31);

    insertAtTail(tail,41);

    insertAtTail(tail,91);

    insertAtTail(tail,77);

    Print(head);

    cout<<"The " << 1 << "rd node from the end in the linked list is "<<nthNodeFromEnd(head,1);

    return 0;
}