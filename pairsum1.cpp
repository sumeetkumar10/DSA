#include<iostream>
#include<unordered_map>
using namespace std;

int pairSum(int arr[],int n,int sum){
    unordered_map<int,int> m;

    int count=0;

    for(int i=0;i<n;i++){
        if(m.find(sum-arr[i])!=m.end()){
            count+=m[sum-arr[i]];
        }
        m[arr[i]]++;
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

    int sum;
    cout<<"Enter the sum"<<endl;
    cin>>sum;

    cout<<"The number of pairs with sum = "<<sum<<" is "<<pairSum(arr,n,sum)<<endl;

    return 0;
}