#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int MinIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[MinIndex]){
                MinIndex=j;
            }
        }
        swap(arr[MinIndex],arr[i]);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr1[],int n,int arr2[],int m,int arr3[]){
    int i=0,j=0,k=0;

    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n){
        arr3[k++]=arr1[i++];
    }
    while(j<m){
        arr3[k++]=arr2[j++];
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>n;

    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    int m;
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>m;

    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    selectionSort(arr1,n);
    printArray(arr1,n);
    selectionSort(arr2,m);
    printArray(arr2,m);

    int arr3[n+m];

    merge(arr1,n,arr2,m,arr3);
    printArray(arr3,n+m);

    return 0;
}