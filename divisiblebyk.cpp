#include<iostream>
using namespace std;

int countElement(int arr[],int n,int k){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%k==0){
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

    int k;
    cout<<"Enter the number"<<endl;
    cin>>k;

    cout<<"Number of elements divisible by "<<k<<" are "<<countElement(arr,n,k)<<endl;

    return 0;
}