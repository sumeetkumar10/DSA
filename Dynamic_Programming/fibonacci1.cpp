#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    // vector<int> dp(n+1);
    // dp[1]=1;
    // dp[0]=0;

    // for(int i=2;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // cout<<n<<" th fibonacci number is "<<dp[n]<<endl;

    int prev1=1;
    int prev2=0;

    if(n==0){
        return 0;
    }

    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;

    return 0;
}