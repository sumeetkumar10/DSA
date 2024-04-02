#include<iostream>
#include<climits>
using namespace std;

int missingNumber(int arr[],int n){
    int a=arr[0];
    int d=(arr[n-1]-arr[0])/n;
    int start=0;
    int end=n-1;
    int missing=-1;

    while(start<=end){
        long long int mid=start+(end-start)/2;

         // if mid and the immediate next element to mid are not in AP, then missing element is arr[mid] + d.
        if(arr[mid+1]-arr[mid]!=d){
            missing = arr[mid]+d;
            break;
        }

         // if mid and the immediate previous element to mid are not in AP, then missing element is arr[mid-1] + d.
        else if(mid>0 && arr[mid]-arr[mid-1]!=d){
            missing = arr[mid-1]+d;
            break;
        }

        else if(arr[mid]==arr[0]+mid*d){
            start=mid+1;
        }

        else{
            end=mid-1;
        }
    }
    return missing;
}

int main(){
    //int arr[]={98,105,119,126};

    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The missing number in the A.P. is "<<missingNumber(arr,n)<<endl;

    return 0;
}