#include<iostream>
using namespace std;

void merge(int *arr,int start,int end){
    int mid=start+(end-start)/2;

    int len1=mid-start+1;
    int len2=end-mid;

    int* first=new int[len1];
    int* second=new int[len2];

    int k=start;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    int index1=0,index2=0;
    k=start;
 
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }
        else{
            arr[k++]=second[index2++];
        }
    }
    while(index1<len1){
        arr[k++]=first[index1++];
    }
    while(index2<len2){
        arr[k++]=second[index2++];
    }
}

void mergeSort(int *arr,int start,int end){
    if(start>=end){
        return ;
    }
    int mid=start+(end-start)/2;

    mergeSort(arr,start,mid);

    mergeSort(arr,mid+1,end);

    merge(arr,start,end);
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

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    printArray(arr,n);

    return 0;
}