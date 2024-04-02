#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start++;
        end--;
    }
}

void rotateArray(int arr[],int n,int d){
    if(d==0){
        return ;
    }

    d=d%n;

    reverseArray(arr,0,d-1);
    reverseArray(arr,d,n-1);
    reverseArray(arr,0,n-1);
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int d;
    cout<<"Enter the number of times you want to rotate the array"<<endl;
    cin>>d;

    rotateArray(arr,n,d);
    printArray(arr,n);

    return 0;
}