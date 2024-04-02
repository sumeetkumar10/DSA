#include<iostream>
#include<climits>
using namespace std;

int solve(int n,int x,int y,int z){
    if(n<0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }

    int a=solve(n-x,x,y,z)+1;
    int b=solve(n-y,x,y,z)+1;
    int c=solve(n-z,x,y,z)+1;

    int ans=max(a,max(b,c));
    return ans;
}

int cutSegments(int n,int x,int y,int z){
    int ans=solve(n,x,y,z);

    if(ans<0){
        return 0;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int x;
    cout<<"Enter the value of x"<<endl;
    cin>>x;

    int y;
    cout<<"Enter the value of x"<<endl;
    cin>>y;

    int z;
    cout<<"Enter the value of x"<<endl;
    cin>>z;

    cout<<"The length of ros is "<<cutSegments(n,x,y,z)<<endl;

    return 0;
}