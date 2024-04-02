#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    // if(n<=1){
    //     return n;
    // }

    // if(dp[n]!=-1){
    //     return dp[n];
    // }

    // return dp[n]=solve(n-1,dp)+solve(n-2,dp);


    vector<int> dp(n+1,0);

    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibonacci(int n){
    vector<int> dp(n+1,-1);

    return solve(n);
}

int main(){
    int n=7;


    cout<<n<<"th fibonacci number is "<<fibonacci(n)<<endl;

    return 0;
}