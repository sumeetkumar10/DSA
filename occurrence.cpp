#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int ans=-1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }

        else if(arr[mid]>key){
            end=mid-1;
        }

        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int lastOcc(int arr[],int n,int key){
    int start=0;
    int end=n-1;
    int ans=-1;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
        }

        else if(arr[mid]>key){
            end=mid-1;
        }

        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the number you want to search in the array"<<endl;
    cin>>key;

    cout<<"The first occurrence of "<<key<<" in the array is at "<<firstOcc(arr,n,key)<<" index in the array."<<endl;
    cout<<"The last occurrence of "<<key<<" in the array is at "<<lastOcc(arr,n,key)<<" index in the array."<<endl;

    return 0;
}