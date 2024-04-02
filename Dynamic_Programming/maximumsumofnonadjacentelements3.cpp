#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n){
    int prev2=0;
    int prev1=arr[0];

    for(int i=1;i<n;i++){
        int excl=prev2+arr[i];
        int incl=prev1+0;

        int ans=max(excl,incl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
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