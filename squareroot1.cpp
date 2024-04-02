#include<iostream>
using namespace std;

long long int Sq(long long int n){
    if(n==0 || n==1){
        return n;
    }
    int i=1,result=1;

    while(result<=n){
        i++;
        result=i*i;
    }
    return i-1;
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The square root of "<<n<<" is "<<Sq(n)<<endl;

    return 0;
}