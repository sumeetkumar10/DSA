#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& prices,int buy,int index){
    if(index==prices.size()){
        return 0;
    }

    int profit=0;
    if(buy){
        profit=max(-prices[index]+solve(prices,0,index+1),solve(prices,1,index+1));
    }
    else{
        profit=max(prices[index]+solve(prices,1,index+1),0+solve(prices,0,index+1));
    }
    return profit;
}

int maxProfit(vector<int>& prices){
    return solve(prices,1,0);
}

int main(){
    vector<int> prices={7,1,5,3,6,4};

    cout<<maxProfit(prices);

    return 0;
}