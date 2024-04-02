#include<iostream>
using namespace std;

bool isPerfectSquare(long long int n){
    for(long long int i=1;i*i<=n;i++){
        if(i*i==n){
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