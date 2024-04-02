#include<iostream>
using namespace std;

int minMerge(int* arr,int n){
    int count=0;
    for(int i=0,j=n-1;i<=j;){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else if(arr[i]>arr[j]){
            j--;
            arr[j]+=arr[j+1];
            count++;
        }
        else{
            i++;
            arr[i]+=arr[i-1];
            count++;
        }
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

    cout<<"The minimum number of merge operations to make the array palindrome is "<<minMerge(arr,n)<<endl;
    
    return 0;
}