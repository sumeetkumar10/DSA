#include<iostream>
#include<climits>
using namespace std;

int maxSubarraySum(int arr[],int n){
    int sum=0,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }

        if(sum<0){
            sum=0;
        }

        if(maxi<0){
            maxi=0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The maximum Subarray Sum in the array is "<<maxSubarraySum(arr,n)<<endl;

    return 0;
}