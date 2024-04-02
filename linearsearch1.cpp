#include<iostream>
using namespace std;

bool LinearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the number you want to search in the array"<<endl;
    cin>>key;

    if(LinearSearch(arr,n,key)==true){
        cout<<key<<" is present in the array."<<endl;
    }
    else{
        cout<<key<<" is not present in the array."<<endl;
    }

    return 0;
}