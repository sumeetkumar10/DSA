#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& prices,int buy,int index,vector<vector<int>>& dp){
    if(index==prices.size()){
        return 0;
    }

    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }

    int profit=0;
    if(buy){
        profit=max(-prices[index]+solve(prices,0,index+1,dp),solve(prices,1,index+1,dp));
    }
    else{
        profit=max(prices[index]+solve(prices,1,index+1,dp),0+solve(prices,0,index+1,dp));
    }
    return dp[index][buy]=profit;
}

int maxProfit(vector<int>& prices){
    vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
    int ans = solve(prices,1,0,dp);
    return ans;
}

int main(){
    vector<int> prices={7,1,5,3,6,4};

    cout<<maxProfit(prices);

    return 0;
}