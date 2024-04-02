#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    vector<int> dp(n+1,0);
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        int ans=(i-1)*(dp[i-1]+dp[i-2]);
        dp[i]=ans;
    }
    return dp[n];
}

int countDerangements(int n){
    return solve(n);
}

int main(){
    int n=5;

    cout<<"The number of derangements will be "<<countDerangements(n)<<endl;

    return 0;
}