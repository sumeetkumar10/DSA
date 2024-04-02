#include<iostream>
using namespace std;

int getPivot(int arr[],int n){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    while(start<end){
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

int main(){
    int n;
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The sorted array is rotated "<<getPivot(arr,n)<<" times."<<endl;

    return 0;
}