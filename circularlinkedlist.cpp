#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }

    }
};

void insertNode(node* &tail,int element,int d){
    //assuming that the element is present in the list
    if(tail==NULL){
        node* newNode=new node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        //non-empty list

        node* curr=tail;

        while(curr->data!=element){
            curr=curr->next;
        }

        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }

}

int countNodes(node* tail){
    node* temp=tail;
    int count=0;

    if(tail!=NULL){
        do{
            temp=temp->next;
            count++;
        }
        while(temp!=tail);
    }
    return count;
}

void print(node* tail){
    node* temp=tail;

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}

int main(){
    node* tail=NULL;

    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,5,6);
    print(tail);

    insertNode(tail,9,10);
    print(tail);

    cout<<"There are "<<countNodes(tail)<<" nodes in the given Circular Linked List."<<endl;

    return 0;
}