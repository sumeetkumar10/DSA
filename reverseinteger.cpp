#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    int num=n;

    int reverse=0;
    while(n>0 or n<0){
        int lastDigit=n%10;

        reverse=reverse*10+lastDigit;

        n=n/10;
    }

    cout<<"The reverse of "<<num<<" is "<<reverse<<"."<<endl;

    return 0;
}