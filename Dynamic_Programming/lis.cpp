#include<iostream>
using namespace std;

int solve(int arr[],int n,int curr,int prev){
    if(curr==n){
        return 0;
    }

    int incl=0;
    if(prev==-1 || arr[curr]>arr[prev]){
        incl=1+solve(arr,n,curr+1,curr);
    }
    int excl=0+solve(arr,n,curr+1,prev);

    int ans=max(incl,excl);
    return ans;
}

int longestSubsequence(int arr[],int n){
    return solve(arr,n,0,-1);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The longest subsequence in the array is of "<<longestSubsequence(arr,n)<<" size."<<endl;

    return 0;
}