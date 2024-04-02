#include<iostream>
#include<math.h>
using namespace std;

long long int Sq(long long int n){
    int sqr=sqrt(n);
    int result=(int)(sqr);
    return result;
}

int main(){
    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;

    cout<<"The square root of "<<n<<" is "<<Sq(n)<<endl;

    return 0;
}