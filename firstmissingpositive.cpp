#include<iostream>
using namespace std;

bool Search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int firstMissing(int arr[],int n){
    for(int i=1;i<=n;i++){
        if(Search(arr,n,i)==false){
            //first missing positive
            return i;
        }
    }
    //return n+1 if first missing positive is not present
    return n+1;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The first missing number is "<<firstMissing(arr,n);

    return 0;
}