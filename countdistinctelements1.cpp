#include<iostream>
#include<algorithm>
using namespace std;

int countDistinct(int arr[],int n){
    sort(arr,arr+n);

    int count=0;
    for(int i=0;i<n;i++){
        while(i<n-1 && arr[i]==arr[i-1]){
            i++;
        }
        count++;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Number of distinct elements = "<<countDistinct(arr,n)<<endl;

    return 0;
}