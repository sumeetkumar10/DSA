#include<iostream>
#include<map>
using namespace std;

int longestSubarrayWithSumk(int arr[],int n,long long int k){
    map<long long int,int> preSumMap;
    long long int sum=0;
    int maxLen=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        long long int rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len=i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        preSumMap[sum]=i;
    }
    return maxLen;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    cout<<"The longest length of the subarray with sum "<<k<<" is "<<longestSubarrayWithSumk(arr,n,k)<<endl;

    return 0;
}