#include<iostream>
#include<map>
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

bool isCyclePresent(Node* &head){
    if(head==NULL){
        return false;
    }

    map<Node*,bool> visited;
    Node* temp=head;

    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }

        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

Node* floydDetectCycle(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}

Node* getIntersectionPoint(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* slow=head;
    Node* intersection=floydDetectCycle(head);

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    if(head==NULL){
        return ;
    }

    Node* startOfLoop=getIntersectionPoint(head);
    Node* temp=startOfLoop;

    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}

int main(){
    Node* Node1=new Node(54);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,27);

    insertAtTail(tail,36);

    insertAtTail(tail,81);

    insertAtTail(tail,72);

    Print(head);

    tail->next=head->next;
    removeLoop(head);
    Print(head);

    if(floydDetectCycle(head)!=NULL){
        cout<<"Cycle is Present in Linked List."<<endl;
    }
    else{
        cout<<"Cycle is not Present in Linked List."<<endl;
    }

    cout<<"The Starting Point of the loop is "<<getIntersectionPoint(head)->data<<endl;

    return 0;
}