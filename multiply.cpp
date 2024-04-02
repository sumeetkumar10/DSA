#include<iostream>
using namespace std;

int multiply(int a,int b){
    int mod=1e9+7;
    long long int ret=(a%mod);
    ret*=(b%mod);
    ret%=mod;
    return ret;
}

int main(){
    int a,b;
    cin>>a>>b;

    cout<<multiply(a,b);

    return 0;
}