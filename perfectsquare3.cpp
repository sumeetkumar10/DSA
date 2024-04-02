#include<iostream>
using namespace std;

bool isPerfectSquare(long long int n){
    int start=1;
    int end=n;

    while(start<=end){
        long long int mid=start+(end-start)/2;

        if(mid*mid==n){
            return true;
        }
        else if(mid * mid > n){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    if(isPerfectSquare(n)){
        cout<<n<<" is a perfect square."<<endl;
    }
    else{
        cout<<n<<" is not a perfect square."<<endl;
    }

    return 0;
}