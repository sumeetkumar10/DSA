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

int binToDec(int n){
    int ans=0,i=0;

    while(n!=0){
        int digit=n%10;
        if(digit==1){
            ans+=power(2,i);
        }
        i++;
        n/=10;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The Decimal Equivalent of "<<n<<" is "<<binToDec(n)<<endl;

    return 0;
}