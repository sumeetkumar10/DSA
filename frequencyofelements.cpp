#include<iostream>
using namespace std;

int countOfElement(int arr[],int n,int k){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
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

    cout<<k<<" occurs "<<countOfElement(arr,n,k)<<" times in the array."<<endl;

    return 0;
}