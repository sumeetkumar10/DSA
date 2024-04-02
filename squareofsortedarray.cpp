#include<iostream>
#include<algorithm>
using namespace std;

void PrintArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sqOfArr(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=arr[i]*arr[i];
    }
    sort(arr,arr+n);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sqOfArr(arr,n);
    PrintArray(arr,n);

    return 0;
}