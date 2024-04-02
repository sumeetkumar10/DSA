#include<iostream>
#include<math.h>
using namespace std;

bool isPerfectSquare(long double n){
    if(n>=0){
        long long int sqr=sqrt(n);

        if(sqr*sqr==n){
            return true;
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