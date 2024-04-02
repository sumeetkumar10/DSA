//DP with Binary Search
#include<iostream>
#include<vector>
using namespace std;

int solve(int arr[],int n){
    if(n==0){
        return 0;
    }

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1;i<n;i++){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[index]=arr[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int arr[],int n){
    return solve(arr,n);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want tp create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The Longest Increasing subsequence is of "<<longestSubsequence(arr,n)<<" size."<<endl;

    return 0;
}