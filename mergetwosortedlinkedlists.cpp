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

Node* mergeTwoSortedLinkedLists(Node* &first,Node* &second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }

    if(first->next==NULL){
        first->next=second;
        return first;
    }

    Node* curr1=first;
    Node* next1=curr1->next;

    Node* curr2=second;
    Node* next2=curr2->next;

    while(next1!=NULL && curr2!=NULL){
        if((curr2->data<=next1->data) && (curr2->data>=curr1->data)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;

            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}

int main(){
    Node* Node1=new Node(1);

    Node* head1=Node1;
    Node* tail1=Node1;

    insertAtTail(tail1,3);

    insertAtTail(tail1,5);

    Print(head1);

    Node* Node2=new Node(2);

    Node* head2=Node2;
    Node* tail2=Node2;

    insertAtTail(tail2,4);

    insertAtTail(tail2,5);

    Print(head2);

    cout<<"The Linked List obtained after merging the two sorted Linked Lists is "<<endl;

    Node* ans=mergeTwoSortedLinkedLists(head1,head2);
    Print(ans);

    return 0;
}