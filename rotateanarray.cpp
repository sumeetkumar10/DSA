#include<iostream>
using namespace std;

void leftRotateByOne(int arr[],int n){
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

void leftRotate(int arr[],int n,int d){
    for(int i=0;i<d;i++){
        leftRotateByOne(arr,n);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
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
    cout<<"Enter the value of d"<<endl;
    cin>>d;

    leftRotate(arr,n,d);
    printArray(arr,n);

    return 0;
}