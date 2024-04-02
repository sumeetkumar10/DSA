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

void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* deleteNode(Node* &head,int x){
    Node* curr=head;
    Node* prev=NULL;

    int count=1;

    while(curr!=NULL){
        if(count==x){
            if(prev==NULL){
                return curr->next;
            }
            else{
                prev->next=curr->next;
                delete curr;
                return head;
            }
        }
        else{
            prev=curr;
            curr=curr->next;
            count++;
        }
    }
    return head;
}

/*
Node* deleteNode(Node* &head,int x)
{
    if(head==NULL){
        return NULL;
    }
    
    if(x==1){
        Node* temp=head;
        
        head=head->next;
        
        delete temp;
        
        return head;
    }
    
    x--;
    
    head->next=deleteNode(head->next,x);
    
    return head;
}
*/

int main(){
    Node* Node1=new Node(57);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,60);

    insertAtTail(tail,63);

    insertAtTail(tail,64);

    insertAtTail(tail,81);

    insertAtTail(tail,27);

    insertAtTail(tail,36);

    insertAtTail(tail,9801);

    print(head);

    deleteNode(head,2);
    print(head);

    return 0;
}