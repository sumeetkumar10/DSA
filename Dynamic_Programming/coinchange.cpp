#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(int coins[],int n,int amount,vector<int>& dp){
    //Step 1: Base Case
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }

    //Step 3: Memoization
    if(dp[amount]!=-1){
        return dp[amount];
    }

    //Step 2: Recursion
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        int ans=solve(coins,n,amount-coins[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    dp[amount]=mini;
    return dp[amount];
}

int minCoins(int coins[],int n,int amount){
    vector<int> dp(amount+1,-1);
    int ans=solve(coins,n,amount,dp);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* coins=new int[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int amount;
    cout<<"Enter the amount"<<endl;
    cin>>amount;

    cout<<"The fewest number of coins needed is "<<minCoins(coins,n,amount);

    return 0;
}