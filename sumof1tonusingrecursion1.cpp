#include<iostream>
using namespace std;

int sumTilln(int n){
    if(n==0 || n==1){
        return 1;
    }

    return n+sumTilln(n-1);
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The sum of 1 to "<<n<<" is "<<sumTilln(n)<<endl;

    return 0;
}