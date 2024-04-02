#include<iostream>
using namespace std;

void leftRotate(int arr[],int n,int d){
    d=d%n;

    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }

    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
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

    int d;
    cout<<"Enter the number of times you want to rotate the array"<<endl;
    cin>>d;

    leftRotate(arr,n,d);
    printArray(arr,n);

    return 0;
}