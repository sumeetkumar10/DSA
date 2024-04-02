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

void PrintCircular(Node* &head){
    Node* temp=head;

    do{
        temp=temp->next;
        cout<<temp->data<<" ";
    }while(temp!=head);
    cout<<endl;
}

Node* convertSinglyToCircular(Node* &head){
    Node* curr=head;

    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=head;
    return curr;
}

int main(){
    Node* Node1=new Node(99);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,100);

    insertAtTail(tail,101);

    insertAtTail(tail,102);

    insertAtTail(tail,103);

    Print(head);

    Node* ans=convertSinglyToCircular(head);
    PrintCircular(ans);
    
    return 0;
}