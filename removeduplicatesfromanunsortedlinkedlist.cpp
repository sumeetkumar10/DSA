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

Node* removeDuplicates(Node* &head){
    Node* ptr1;
    Node* ptr2;

    ptr1=head;

    while(ptr1!=NULL){
        ptr2=ptr1->next;

        Node* prev=ptr1;

        while(ptr2!=NULL){
            if(ptr1->data==ptr2->data){
                prev->next=ptr2->next;

                delete ptr2;

                ptr2=prev->next;
            }
            else{
                prev=ptr2;
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
    return head;
}

int main(){
    Node* Node1=new Node(4);

    Node* tail=Node1;
    Node* head=Node1;

    insertAtTail(tail,5);

    insertAtTail(tail,6);

    insertAtTail(tail,4);

    insertAtTail(tail,7);

    insertAtTail(tail,3);

    insertAtTail(tail,4);

    insertAtTail(tail,1);

    insertAtTail(tail,9);

    insertAtTail(tail,4);

    insertAtTail(tail,7);

    insertAtTail(tail,4);

    cout<<"Original Linked List"<<endl;
    Print(head);

    cout<<"Linked List after removing duplicate elements"<<endl;
    Node* newHead=removeDuplicates(head);
    Print(newHead);

    return 0;
}