#include<iostream>
using namespace std;

bool isPerfectSquare(long long int n){
    long long int sum=0;
    for(int i=1;sum<n;i+=2){
        sum+=i;
        if(sum==n){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n=9801;

    if(isPerfectSquare(n)){
        cout<<n<<" is a perfect square."<<endl;
    }
    else{
        cout<<n<<" is not a perfect square."<<endl;
    }

    return 0;
}