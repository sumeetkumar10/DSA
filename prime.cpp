#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    int m;
    cin>>m;

    if(isPrime(n)){
        cout<<"Yes "<<n<<" is a prime number."<<endl;
    }
    else{
        cout<<n<<" is not a prime number."<<endl;
    }

    for(int i=n;i<=m;i++){
        if(isPrime(i)){
            cout<<i<<endl;
        }
    }

    return 0;
}