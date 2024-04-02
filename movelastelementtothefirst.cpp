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

Node* moveLastElement(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* secondLast=NULL;
    Node* last=head;

    while(last->next!=NULL){
        secondLast=last;
        last=last->next;
    }

    secondLast->next=NULL;
    last->next=head;
    head=last;

    return head;
}

int main(){
    Node* Node1=new Node(54);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,96);

    insertAtTail(tail,36);

    insertAtTail(tail,81);

    insertAtTail(tail,48);

    insertAtTail(tail,72);

    insertAtTail(tail,27);

    Print(head);

    Node* newList=moveLastElement(head);
    Print(newList);

    return 0;
}