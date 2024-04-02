#include<iostream>
using namespace std;

int solve(int n){
    int prev2=0;
    int prev1=1;

    for(int i=3;i<=n;i++){
        int ans=(i-1)*(prev1+prev2);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int countDerangements(int n){
    return solve(n);
}

int main(){
    int n=4;

    cout<<"The number of derangements will be "<<countDerangements(n)<<endl;

    return 0;
}