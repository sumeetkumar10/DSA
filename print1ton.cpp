#include<iostream>
using namespace std;

void increasing(int x,int n){
    if(x>n){
        return ;
    }

    cout<<x<<endl;
    increasing(x+1,n);
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    increasing(1,n);

    return 0;
}