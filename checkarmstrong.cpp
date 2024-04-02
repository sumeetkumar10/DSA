#include<iostream>
using namespace std;

int power(int x,int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }

    int ans=power(x,n/2);
    if(n%2==0){
        return ans*ans;
    }
    else{
        return x*ans*ans;
    }
}

bool isArmstrong(int n){
    int original=n;
    int lastDigit=0;
    int ans=0;
    while(n!=0){
        lastDigit=n%10;
        ans+=power(lastDigit,3);
        n/=10;
    }
    if(ans==original){
        return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    if(isArmstrong(n)){
        cout<<n<<" is an Armstrong number."<<endl;
    }
    else{
        cout<<n<<" is not an Armstrong number."<<endl;
    }

    return 0;
}