#include<iostream>
using namespace std;

int lastIndex(int arr[],int n,int index,int target){
    if(index<0){
        return -1;
    }

    if(arr[index]==target){
        return index;
    }
    else{
        return lastIndex(arr,n,index-1,target);
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

    int target;
    cout<<"Enter the number which you want to search in the array"<<endl;
    cin>>target;

    cout<<"The last occurrence of "<<target<<" in the array is at "<<lastIndex(arr,n,n-1,target)<<" index."<<endl;

    return 0;
}