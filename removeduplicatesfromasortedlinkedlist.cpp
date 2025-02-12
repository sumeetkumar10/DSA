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

    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            Node* next_next=curr->next->next;
            Node* nodeToDelete=curr->next;
            delete(nodeToDelete);
            curr->next=next_next;
        }
        else{
            curr=curr->next;
        }
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

    insertAtTail(tail,72);

    insertAtTail(tail,72);

    insertAtTail(tail,72);

    insertAtTail(tail,96);

    insertAtTail(tail,96);

    Print(head);

    Node* sortedList=removeDuplicates(head);
    Print(sortedList);

    return 0;
}