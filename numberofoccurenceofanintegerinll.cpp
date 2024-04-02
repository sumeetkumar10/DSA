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

int countOccurence(Node* head,int key){
    Node* temp=head;
    int count=0;

    while(temp!=NULL){
        if(temp->data==key){
            count++;
        }
        temp=temp->next;
    }
    return count;
}

int main(){
    Node* Node1=new Node(99);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,96);

    insertAtTail(tail,99);

    insertAtTail(tail,97);

    insertAtTail(tail,99);

    int key=99;

    cout<<key<<" Occurred "<<countOccurence(head,key)<<" times in the Linked List."<<endl;

    return 0;
}