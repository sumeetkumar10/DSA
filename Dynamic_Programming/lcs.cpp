#include<iostream>
using namespace std;

int solve(string& s1,string& s2,int x,int y){
    if(x<0 || y<0){
        return 0;
    }

    if(s1[x]==s2[y]){
        return 1+solve(s1,s2,x-1,y-1);
    }
    else{
        return max(solve(s1,s2,x-1,y),solve(s1,s2,x,y-1));
    }
}

int lcs(string s1,string s2){
    return solve(s1,s2,s1.length()-1,s2.length()-1);
}

int main(){
    string s1="ABCDGH";
    string s2="AEDFHR";

    cout<<"The Longest Common subsequence is of the length "<<lcs(s1,s2)<<endl;

    return 0;
}