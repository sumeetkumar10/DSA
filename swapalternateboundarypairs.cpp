#include<iostream>
using namespace std;

void swapAlternateBoundaryPairs(int arr[],int n){
    int start=0;
    int end=n-1;

    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start+=2;
        end-=2;
    }
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

    printArray(arr,n);
    swapAlternateBoundaryPairs(arr,n);
    printArray(arr,n);

    return 0;
}