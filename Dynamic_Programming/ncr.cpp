#include<iostream>
#define mod 1000000007;
using namespace std;

int solve(int n,int r){
    if(n<r){
        return 0;
    }
    if(r==0 || n==r){
        return 1;
    }

    int incl=solve(n-1,r-1);
    int excl=solve(n-1,r);

    int ans=(incl+excl)%mod;
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