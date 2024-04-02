#include<iostream>
using namespace std;

int sumTilln(int n,int sum){
    if(n==0){
        return sum;
        return 1;
    }

    sumTilln(n-1,sum+n);
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<"The sum of "<<n<<" natural numbers is "<<sumTilln(n,0);

    return 0;
}