#include<iostream>
using namespace std;

int getPivot(int arr[],int n){
    int start=0;
    int end=n-1;
    
    while(start<end){
        int mid=start+(end-start)/2;

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
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Pivot is at "<<getPivot(arr,n)<<" index."<<endl;

    return 0;
}