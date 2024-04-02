#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n,int curr,int prev,vector<vector<int>>& dp){
    if(curr==n){
        return 0;
    }

    if(dp[curr][prev+1]!=-1){                                 //Because prev is -1
        return dp[curr][prev+1];
    }

    int incl=0;
    if(prev==-1 || arr[curr]>arr[prev]){                      //First element will always be included
        incl=1+solve(arr,n,curr+1,curr,dp);
    }
    int excl=0+solve(arr,n,curr+1,prev,dp);

    dp[curr][prev+1]=max(incl,excl);
    return dp[curr][prev+1];
}

int longestSubsequence(int arr[],int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(arr,n,0,-1,dp);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The longest subsequence in the array is of "<<longestSubsequence(arr,n)<<" size."<<endl;

    return 0;
}