#include<iostream>
using namespace std;

int solve(int n){
    if(n==0){
        return 0;
    }

    int ans=n;
    for(int i=1;i*i<=n;i++){
        int temp=i*i;
        ans=min(ans,1+solve(n-temp));
    }
    return ans;
}

int MinSquares(int n){
    return solve(n);
}

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    cout<<"Minimum number of squares required to form "<<n<<" is "<<MinSquares(n)<<endl;

    return 0;
}