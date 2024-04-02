#include<iostream>
#include<map>
using namespace std;

int subarraySum(int arr[],int n,int k){
    int count=0,prefixSum=0;

    map<int,int> map;
    map[0]=1;

    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        int remove=prefixSum-k;
        count+=map[remove];
        map[prefixSum]++;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the subarray sum"<<endl;
    cin>>k;

    cout<<"There are "<<subarraySum(arr,n,k)<<" subarrays with "<<k<<" sum."<<endl;

    return 0;
}