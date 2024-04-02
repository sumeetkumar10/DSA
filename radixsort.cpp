#include<iostream>
using namespace std;

int getMax(int arr[],int n){
    int ans=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>ans){
            ans=arr[i];
        }
    }
    return ans;
}

void countingSort(int arr[],int n,int place){
    const int max=10;

    int output[n];

    int count[max];

    for(int i=0;i<max;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        count[(arr[i]/place)%10]++;
    }

    for(int i=1;i<max;i++){
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/place)%10]-1]=arr[i];
        count[(arr[i]/place)%10]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(int arr[],int n){
    int max=getMax(arr,n);

    for(int place=1;max/place>0;place*=10){
        countingSort(arr,n,place);
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
    cout<<"Enter the size of the array you want to create "<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    printArray(arr,n);
    radixSort(arr,n);
    printArray(arr,n);

    // int ans=0;
    // for(int i=1;i<=n;i++){
    //     ans=ans^i;
    // }
    // cout<<ans<<endl;

    return 0;
}