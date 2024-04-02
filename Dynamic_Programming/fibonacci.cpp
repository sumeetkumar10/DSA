#include<iostream>
#include<vector>
using namespace std;

int count=0;
int fibonacci(int n,vector<int>& dp){
    //Step 1
    if(n<=1){
        return n;
    }

    //Step 3
    if(dp[n]!=-1){
        return dp[n];
    }

    //Step 2
    dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
    count++;
    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    vector<int> dp(n+1);
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }

    cout<<n<<" th fibonacci number is "<<fibonacci(n,dp)<<endl;
    cout<<count<<endl;

    return 0;
}