#include<iostream>
using namespace std;

int mountain(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The peak of the array is present at "<<mountain(arr,n)<<" index in the array."<<endl;

    return 0;
}