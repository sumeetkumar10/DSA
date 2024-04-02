#include<iostream>
#include<vector>
using namespace std;

int solve(string& s1,string& s2,int x,int y,vector<vector<int>>& dp){
    if(x<0 || y<0){
        return 0;
    }

    if(dp[x][y]!=-1){
        return dp[x][y];
    }

    if(s1[x]==s2[y]){
        return dp[x][y]=1+solve(s1,s2,x-1,y-1,dp);
    }
    else{
        return dp[x][y]=max(solve(s1,s2,x-1,y,dp),solve(s1,s2,x,y-1,dp));
    }
}

int lcs(string s1,string s2){
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    return solve(s1,s2,s1.length()-1,s2.length()-1,dp);
}

int main(){
    string s1="ABCDEFGHIKL";
    string s2="ABFHK";

    cout<<"The Longest Common subsequence is of the length "<<lcs(s1,s2)<<endl;

    return 0;
}