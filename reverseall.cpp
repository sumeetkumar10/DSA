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

node* reverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* curr=head;
    node* prev=NULL;
    node* next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int getLength(node* &head){
    node* temp=head;

    int count=0;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout << "Length: " << count << endl;
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

    cout<<"Original Linked List:"<<endl;
    Print(head);

    getLength(head);

    cout<<"Reversed Linked List:"<<endl;
    node* reversedLL=reverse(head);
    Print(reversedLL);

    return 0;
}