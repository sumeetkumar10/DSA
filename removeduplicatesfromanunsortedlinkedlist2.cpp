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
    if(head==NULL){
        return NULL;
    }

    Node* curr=head;
    Node* temp;

    while(curr!=NULL && curr->next!=NULL){
        temp=curr;
        while(temp->next!=NULL){
            if(curr->data==temp->next->data){
                Node* nodeToDelete=temp->next;
                temp->next=temp->next->next;
                delete(nodeToDelete);
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
    return head;
}

int main(){
    Node* Node1=new Node(24);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,48);

    insertAtTail(tail,48);

    insertAtTail(tail,72);

    insertAtTail(tail,72);

    insertAtTail(tail,27);

    insertAtTail(tail,27);

    insertAtTail(tail,72);

    insertAtTail(tail,27);

    insertAtTail(tail,96);

    Print(head);

    Node* sortedList=removeDuplicates(head);
    Print(sortedList);

    return 0;
}