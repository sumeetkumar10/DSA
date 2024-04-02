#include<iostream>
using namespace std;

int solve(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    int ans=(n-1)*(solve(n-1)+solve(n-2));
    return ans;
}

int countDerangements(int n){
    return solve(n);
}

int main(){
    int n=4;

    cout<<"The number of derangements will be "<<countDerangements(n)<<endl;

    return 0;
}