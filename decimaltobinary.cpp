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

int decToBin(int n){
    int ans=0,i=0;
    while(n!=0){
        int bit=n&1;
        ans=(bit*power(10,i))+ans;
        i++;
        n=n>>1;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The Binary Equivalent of "<<n<<" is "<<decToBin(n)<<endl;

    return 0;
}