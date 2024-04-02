#include<iostream>
using namespace std;

void reverseArray(int arr[],int start,int end){
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[],int d,int n){
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
    cout<<"Enter d"<<endl;
    cin>>d;

    leftRotate(arr,d,n);
    printArray(arr,n);

    return 0;
}