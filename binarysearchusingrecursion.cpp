#include<iostream>
using namespace std;

bool BinarySearch(int arr[],int start,int end,int key){
    if(start>end){
        return false;
    }

    int mid=start+(end-start)/2;

    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]>key){
        return BinarySearch(arr,start,mid-1,key);
    }
    else{
        return BinarySearch(arr,mid+1,end,key);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the number you want to search in the array"<<endl;
    cin>>key;

    bool ans=BinarySearch(arr,0,n-1,key);

    if(ans){
        cout<<"The key is present in the array or not:          "<<ans<<endl;
    }
    else{
        cout<<"The key is present in the array or not:          "<<ans<<endl;
    }

    return 0;
}
