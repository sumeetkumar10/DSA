#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int MinIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[MinIndex]){
                MinIndex=j;
            }
        }
        swap(arr[MinIndex],arr[i]);
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
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionSort(arr,n);
    printArray(arr,n);

    return 0;
}