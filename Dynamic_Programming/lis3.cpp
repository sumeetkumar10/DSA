#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);

    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int incl=0;
            if(prev==-1 || arr[curr]>arr[prev]){
                incl=1+nextRow[curr+1];
            }
            int excl=0+nextRow[prev+1];

            currRow[prev+1]=max(incl,excl);
        }
        nextRow=currRow;
    }
    return nextRow[0];
}

int longestSubsequence(int arr[],int n){
    return solve(arr,n);
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