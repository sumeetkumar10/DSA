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

bool detectCycle(Node* &head){
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

    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection=floydDetectCycle(head);

    if(intersection==NULL){
        return NULL;
    }

    Node* slow=head;

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

    Node* startOfLoop=getStartingNode(head);
    Node* temp=startOfLoop;

    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}

int main(){
    Node* Node1=new Node(5);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,3);

    insertAtTail(tail,4);

    insertAtTail(tail,6);

    insertAtTail(tail,9);

    Print(head);

    if(detectCycle(head)){
        cout<<"There is loop in the linked list."<<endl;
    }
    else{
        cout<<"There is no loop in the linked list."<<endl;
    }

    tail->next=head->next;

    if(floydDetectCycle(head)!=NULL){
        cout<<"Loop is present in the linked list."<<endl;
    }
    else{
        cout<<"No loop is present in the linked list."<<endl;
    }

    Node* startingPoint=getStartingNode(head);
    cout<<"Loop starts at "<<startingPoint->data<<endl;

    removeLoop(head);
    Print(head);

    return 0;
}