#include<iostream>
using namespace std;

int findnCr(int n,int r){
    int ans=1;
    for(int i=0;i<r;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}

int pascalTriangle(int r,int c){
    return findnCr(r-1,c-1);
}

int main(){
    int r;
    cout<<"Enter r"<<endl;
    cin>>r;

    int c;
    cout<<"Enter c"<<endl;
    cin>>c;

    cout<<"The value at "<<r<<" th row and "<<c<<" th column is "<<pascalTriangle(r,c)<<endl;

    return 0;
}