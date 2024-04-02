#include<iostream>
using namespace std;

int solve(int n,int k){
    if(n==1){
        return k;
    }

    if(n==2){
        return k*k;
    }

    int same=solve(n-2,k)*(k-1);
    int different=solve(n-1,k)*(k-1);

    return same+different;
}

int main(){
    int n=5,k=3;

    cout<<"Ans = "<<solve(n,k)<<endl;

    return 0;
}