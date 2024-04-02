#include<iostream>
using namespace std;

void Sort012(int arr[],int n){
    int i=0,j=0,k=n-1;

    while(j<=k){
        if(arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else if(arr[j]==1){
            j++;
        }
        else{
            swap(arr[j],arr[k]);
            k--;
        }
    }
}

void PrintArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Sort012(arr,n);
    PrintArray(arr,n);
    
    return 0;
}