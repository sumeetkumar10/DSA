#include<iostream>
using namespace std;

int findMaximumConsecutiveOnes(int arr[],int n){
    int count=0,maxi=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxi=max(maxi,count);
        }
        else{
            count=0;
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

    cout<<"The maximum number of consecutive ones in the array is "<<findMaximumConsecutiveOnes(arr,n)<<endl;

    return 0;
}