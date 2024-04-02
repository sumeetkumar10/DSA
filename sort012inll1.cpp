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

void insertATTail(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
}

Node* sort012(Node* &head){
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;

    Node* curr=head;
    while(curr!=NULL){
        int val=curr->data;
        if(val==0){
            insertATTail(zeroTail,curr);
        }
        else if(val==1){
            insertATTail(oneTail,curr);
        }
        else if(val==2){
            insertATTail(twoTail,curr);
        }
        curr=curr->next;
    }
    
    //Merging all the three Linked Lists.
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next=NULL;

    head=zeroHead->next;

    //Delete all the three Dummy Nodes.
    delete zeroHead;
    delete oneHead;
    delete twoHead;

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

    insertAtTail(tail,1);

    Print(head);

    Node* ans=sort012(head);
    Print(ans);

    return 0;
}