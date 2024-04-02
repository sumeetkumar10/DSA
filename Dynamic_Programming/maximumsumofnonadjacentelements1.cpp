#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n,vector<int>& dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        arr[0];
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int excl=solve(arr,n-1,dp)+0;
    int incl=solve(arr,n-2,dp)+arr[n];

    dp[n]=max(excl,incl);
    return dp[n];
}

int maxSum(int arr[],int n){
    vector<int> dp(n+1,-1);
    int ans = solve(arr,n,dp);
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

    cout<<"The maximum size of non adjacent elements is "<<maxSum(arr,n)<<endl;

    return 0;
}