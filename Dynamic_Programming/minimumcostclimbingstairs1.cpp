#include<iostream>
using namespace std;

int solve(int cost[],int n){
    int dp[n+1];

    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}

int minCostClimbingStairs(int arr[],int n){
    return solve(arr,n);
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