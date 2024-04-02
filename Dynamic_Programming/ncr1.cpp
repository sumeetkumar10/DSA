#include<iostream>
#include<vector>
#define mod 1000000007;
using namespace std;

int solve(int n,int r,vector<vector<int>>& dp){
    if(n<r){
        return 0;
    }
    if(r==0 || n==r){
        return 1;
    }

    if(dp[n][r]!=-1){
        return dp[n][r];
    }

    int incl=solve(n-1,r-1,dp);
    int excl=solve(n-1,r,dp);

    dp[n][r]=(incl+excl)%mod;
    return dp[n][r];
}

int ncr(int n,int r){
    vector<vector<int>>dp (n+1,vector<int>(r+1,-1));
    return solve(n,r,dp);
}

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    int r;
    cout<<"Enter the value of r"<<endl;
    cin>>r;

    cout<<n<<"c"<<r<<" = "<<ncr(n,r)<<endl;

    return 0;
}