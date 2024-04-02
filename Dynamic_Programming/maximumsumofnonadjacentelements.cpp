#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return arr[0];
    }

    int excl=solve(arr,n-1)+0;
    int incl=solve(arr,n-2)+arr[n];

    int ans=max(excl,incl);
    return ans;
}

int maxSum(int arr[],int n){
    return solve(arr,n);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The maximum size of non adjacent elements is "<<maxSum(arr,n)<<endl;

    return 0;
}