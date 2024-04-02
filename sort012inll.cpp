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

Node* sort012(Node* &head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else if(temp->data==2){
            twoCount++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(zeroCount!=0){
            zeroCount--;
            temp->data=0;
        }
        else if(oneCount!=0){
            oneCount--;
            temp->data=1;
        }
        else if(twoCount!=0){
            twoCount--;
            temp->data=2;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    Node* Node1=new Node(1);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,1);
    
    insertAtTail(tail,0);

    insertAtTail(tail,1);

    insertAtTail(tail,2);

    insertAtTail(tail,0);

    Print(head);

    Node* ans=sort012(head);
    Print(ans);

    return 0;
}