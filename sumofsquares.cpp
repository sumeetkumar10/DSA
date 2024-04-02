#include<iostream>
using namespace std;

long long int sumOfSquares(long long int n){
    long long int sum=(n*(n+1)*(2*n+1))/6;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<sumOfSquares(n);

    return 0;
}