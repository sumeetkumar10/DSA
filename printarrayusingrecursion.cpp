#include<iostream>
using namespace std;

void printArray(int arr[],int n,int index){
    if(index==n){
        return ;
    }

    cout<<arr[index]<<" ";

    printArray(arr,n,index+1);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    printArray(arr,n,0);

    return 0;
}