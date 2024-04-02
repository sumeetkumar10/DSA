#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n,int target,vector<int>& dp){
    if(target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }

    if(dp[target]!=-1){
        return dp[target];
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=solve(arr,n,target-arr[i],dp);
    }
    dp[target]=ans;
    return dp[target];
}

int combinationSum4(int arr[],int n,int target){
    vector<int> dp(target+1,-1);
    int ans=solve(arr,n,target,dp);
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

    int target;
    cout<<"Enter the target"<<endl;
    cin>>target;

    cout<<"Answer is "<<combinationSum4(arr,n,target)<<endl;

    return 0;
}