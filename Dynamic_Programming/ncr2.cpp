#include<iostream>
#include<vector>
#define mod 1000000007;
using namespace std;

int solve(int n,int r){
    vector<vector<int>>dp (n+1,vector<int>(r+1,0));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<r+1;j++){
            if(i==j || j==0){
                dp[i][j]=1;
            }
            if(j==1){
                dp[i][j]=i;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<r+1;j++){
            if(i<j){
                continue;
            }
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
    return dp[n][r];
}

int ncr(int n,int r){
    return solve(n,r);
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