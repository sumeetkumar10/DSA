#include<iostream>
using namespace std;

int getMax(int arr[],int n){
    int ans=arr[0];
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    return ans;
}

int getMin(int arr[],int n){
    int ans=arr[0];
    for(int i=0;i<n;i++){
        ans=min(ans,arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The maximum number present in the array is "<<getMax(arr,n)<<endl;
    cout<<"The minimum number present in the array is "<<getMin(arr,n)<<endl;

    cout<<"The sum of maximum and minimum number of the array is "<<getMax(arr,n)+getMin(arr,n)<<endl;

    return 0;
}