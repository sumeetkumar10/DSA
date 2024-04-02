#include<bits/stdc++.h>
using namespace std;

void kLargest(int arr[],int n,int k){
    sort(arr,arr+n,greater<int>());

    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
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
    cout<<"Enter the number"<<endl;
    cin>>k;

    kLargest(arr,n,k);

    return 0;
}