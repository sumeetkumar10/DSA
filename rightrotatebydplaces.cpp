#include<iostream>
using namespace std;

void rightRotate(int* arr,int n){
    int temp=arr[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
}

void rightRotateBydPlaces(int* arr,int n,int d){
    if(d<0 || d>=n){
        return ;
    }

    for(int i=0;i<d;i++){
        rightRotate(arr,n);
    }
}

void printArray(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the arary you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int d;
    cout<<"Enter the value of d"<<endl;
    cin>>d;

    rightRotateBydPlaces(arr,n,d);
    printArray(arr,n);

    return 0;
}