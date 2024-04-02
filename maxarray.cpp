#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int MaxNo=INT_MIN;
    int MinNo=INT_MAX;

    for(int i=0;i<n;i++){
        if(arr[i]>MaxNo){
            MaxNo=arr[i];
        }
        if(arr[i]<MinNo){
            MinNo=arr[i];
        }
    }

    cout<<"The maximum number present in the array is "<<MaxNo<<endl;
    cout<<"The minimum number present in the array is "<<MinNo<<endl;

    cout<<"The sum of maximum and minimum number of the array is "<<MinNo+MaxNo<<endl;

    return 0;
}