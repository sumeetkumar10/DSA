#include<iostream>
using namespace std;

int getPivot(int arr[],int n,int key){
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

int BinarySearch(int arr[],int s,int e,int key){
    int start=s;
    int end=e;

    while(start<=end){
        int mid=start+(end-start)/2;

        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
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

    int pivot=getPivot(arr,n,key);
    if(key>=arr[pivot] && key<=arr[n-1]){
        cout << key << " is present at "<< BinarySearch(arr,pivot,n-1,key) << " index in the array." << endl;
    }
    else{
        cout << key << " is present at "<< BinarySearch(arr,0,pivot-1,key) << " index in the array." << endl;
    }

    return 0;
}