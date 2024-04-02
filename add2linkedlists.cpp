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

Node* reverse(Node* &head){
    Node* curr=head;
    Node* forward=NULL;
    Node* prev=NULL;

    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void insertAtTail(Node* &head,Node* &tail,int digit){
    Node* temp=new Node(digit);
    if(head==NULL){
        head=temp;
        tail=temp;
        return ;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node* add(Node* &first,Node* &second){
    int carry=0;

    Node* Head=NULL;
    Node* Tail=NULL;

    while(first!=NULL && second!=NULL){
        int sum=first->data+second->data+carry;
        int digit=sum%10;
        insertAtTail(Head,Tail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        int sum=first->data+carry;
        int digit=sum%10;
        insertAtTail(Head,Tail,digit);
        carry=sum/10;
        first=first->next;
    }
    while(second!=NULL){
        int sum=second->data+carry;
        int digit=sum%10;
        insertAtTail(Head,Tail,digit);
        carry=sum/10;
        second=second->next;
    }
    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        insertAtTail(Head,Tail,digit);
        carry=sum/10;
    }
    return Head;
}

Node* add2Lists(Node* first,Node* second){
    first=reverse(first);
    second=reverse(second);

    Node* ans=add(first,second);
    ans=reverse(ans);
    return ans;
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

    insertAtTail(tail2,5);

    insertAtTail(tail2,5);

    Print(head2);

    cout<<"The sum of the numbers represented by the Linked List is "<<endl;
    Node* ans=add2Lists(head1,head2);
    Print(ans);

    return 0;
}