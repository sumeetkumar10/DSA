#include<iostream>
using namespace std;

//dutch national flag algorithm

void sort012(int arr[],int n){
    int start=0;
    int end=n-1;
    int mid=0;
    int temp;

    while(mid<=end){
        switch(arr[mid]){
            case 0:{
                temp=arr[start];
                arr[start]=arr[mid];
                arr[mid]=temp;
                start++;
                mid++;
                break;
            }
            case 1:{
                mid++;
                break;
            }
            case 2:{
                temp=arr[mid];
                arr[mid]=arr[end];
                arr[end]=temp;
                end--;
                break;
            }
        }
    }

}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort012(arr,n);
    printArray(arr,n);

    return 0;
}