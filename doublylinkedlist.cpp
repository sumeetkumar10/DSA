#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* previous;
    node* next;

    node(int data){
        this->data=data;
        this->previous=NULL;
        this->next=NULL;
    }
};

void insertAtHead(node* &head,int d){
    if(head==NULL){
        node* temp=new node(d);
        head=temp;
    }
    else{
        node* temp=new node(d);
        temp->next=head;
        head->previous=temp;
        head=temp;
    }
}

void insertAtTail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    temp->previous=tail;
    tail=temp;
}

void insertAtPosition(node* &head,node* &tail,int position,int d){
    if(position==1){
        insertAtHead(head,d);
        return ;
    }

    int count=1;
    node* temp=head;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,d);
        return ;
    }

    node* nodeToInsert=new node(d);
    nodeToInsert->next=temp->next;
    temp->next->previous=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->previous=temp;
}

int getLength(node* &head){
    node* temp=head;

    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void Print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* node1=new node(18);

    node* head=node1;
    node* tail=node1;

    cout<<"Insert At Head"<<endl;
    Print(head);

    cout<<"Length "<<getLength(head)<<endl;

    insertAtHead(head,36);
    Print(head);

    cout<<"Length "<<getLength(head)<<endl;

    insertAtHead(head,54);
    Print(head);

    insertAtHead(head,72);
    Print(head);

    insertAtHead(head,90);
    Print(head);

    insertAtHead(head,108);
    Print(head);

    cout<<"Insert At Tail"<<endl;
    insertAtTail(tail,36);
    Print(head);

    insertAtTail(tail,54);
    Print(head);

    insertAtTail(tail,72);
    Print(head);

    insertAtTail(tail,90);
    Print(head);

    insertAtTail(tail,108);
    Print(head);

    cout<<"Insert At Position"<<endl;
    insertAtPosition(head,tail,3,6);
    Print(head);

    insertAtPosition(head,tail,5,45);
    Print(head);
    
    cout<<"Length "<<getLength(head)<<endl;

    return 0;
}