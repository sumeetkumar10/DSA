#include<iostream>
#include<vector>
using namespace std;

int solve(int n,vector<int>& dp){
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans=n;
    for(int i=1;i*i<=n;i++){
        int temp=i*i;
        ans=min(ans,1+solve(n-temp,dp));
    }
    dp[n]=ans;
    return dp[n];
}

int MinSquares(int n){
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    cout<<"Minimum number of squares required to form "<<n<<" is "<<MinSquares(n)<<endl;

    return 0;
}