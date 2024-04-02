#include<iostream>
using namespace std;

int solve(int cost[],int n,int dp[]){
    //Step 1: Base Case
    if(n<=1){
        return cost[n];
    }

    //Step 3: Memoization
    if(dp[n]!=-1){
        return dp[n];
    }

    //Step 2: Recursion
    dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return dp[n];
}

int minCostClimbingStairs(int cost[],int n){
    int dp[n+1];
    for(int i=1;i<n;i++){
        dp[i]=-1;
    }
    int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* cost=new int[n];
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    cout<<"The minimum cost of climbing the stairs is "<<minCostClimbingStairs(cost,n)<<endl;

    return 0;
}