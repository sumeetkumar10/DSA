#include<iostream>
#include<vector>
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

bool checkPalindrome(vector<int>& arr,int start,int end){
    // while(start<=end){
    //     if(arr[start]!=arr[end]){
    //         return false;
    //     }
    //     start++;
    //     end--;
    // }
    // return true;

    if(start==end){
        return true;
    }

    if(arr[start]!=arr[end]){
        return false;
    }

    if(start<end+1){
        return checkPalindrome(arr,start+1,end-1);
    }
}

bool isPalindrome(Node* &head){
    vector<int> arr;

    Node* temp=head;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkPalindrome(arr,0,arr.size()-1);
}

int main(){
    Node* Node1=new Node(3);

    Node* head=Node1;
    Node* tail=Node1;

    insertAtTail(tail,6);

    insertAtTail(tail,9);
    
    insertAtTail(tail,9);

    insertAtTail(tail,6);

    insertAtTail(tail,3);

    Print(head);

    if(isPalindrome(head)){
        cout<<"The Linked List is palindrome."<<endl;
    }
    else{
        cout<<"The Linked List is not palindrome."<<endl;
    }

    return 0;
}