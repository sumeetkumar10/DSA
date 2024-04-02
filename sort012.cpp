#include<iostream>
#include<algorithm>
using namespace std;

void sort012(int arr[],int n){
    //sort(arr,arr+n);

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

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array tou want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort012(arr,n);
    printArray(arr,n);

    return 0;
}