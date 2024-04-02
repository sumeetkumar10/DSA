#include<iostream>
using namespace std;

void sort012(int arr[],int n){
    int count[3]={0,0,0};

    int i=0;

    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    while(count[0]--){
        arr[i++]=0;
    }

    while(count[1]--){
        arr[i++]=1;
    }

    while(count[2]--){
        arr[i++]=2;
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
    sort012(arr,n);
    printArray(arr,n);

    return 0;
}