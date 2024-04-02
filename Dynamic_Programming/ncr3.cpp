#include<iostream>
#include<vector>
#define mod 1000000007;
using namespace std;

int solve(int n,int r){
    vector<int> prev(r+1,0);
    vector<int> curr(r+1,0);

    prev[0]=1;
    curr[0]=1;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<r+1;j++){
            if(i<j){
                continue;
            }
            curr[j]=(prev[j-1]+prev[j])%mod;
        }
        prev=curr;
    }
    return prev[r];
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