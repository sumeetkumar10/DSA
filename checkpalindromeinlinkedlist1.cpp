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

Node* getMiddle(Node* &head){
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* reverse(Node* &head){
    Node* curr=head;
    Node* next=NULL;
    Node* prev=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(Node* &head){
    if(head==NULL || head->next==NULL){
        return true;
    }

    //Find middle of Linked List.
    Node* mid=getMiddle(head);
    
    //Split Linked List into two halves.
    Node* temp=mid->next;
    mid->next=reverse(temp);
    
    //Compare the two halves.
    Node* head1=head;
    Node* head2=mid->next;

    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    //Repeat Second Step.
    temp=mid->next;
    mid->next=reverse(temp);

    return true;
}

int main(){
    Node* Node1=new Node(6);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,8);

    insertAtTail(tail,7);

    insertAtTail(tail,8);

    insertAtTail(tail,6);

    Print(head);

    if(isPalindrome(head)){
        cout<<"The Linked List is palindrome."<<endl;
    }
    else{
        cout<<"The Linked List is not palindrome."<<endl;
    }

    return 0;
}