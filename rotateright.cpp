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

Node* rotateRight(Node* &head,int k){
    if(head==NULL){
        return head;
    }

    int count=1;
    Node* tail=head;

    while(tail->next!=NULL){
        count++;
        tail=tail->next;
    }
    tail->next=head;
    int size=count-k%count;

    for(int i=0;i<size;i++){
        tail=tail->next;
    }
    head=tail->next;
    tail->next=NULL;
    return head;
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

    int k=1;

    Node* newLL=rotateRight(head,k);
    Print(newLL);
    
    return 0;
}