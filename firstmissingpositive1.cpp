#include<iostream>
#include<algorithm>
using namespace std;

int firstMissing(int arr[],int n){
    if(n==0){
        return 1;
    }

    sort(arr,arr+n);

    int counter=1;

    for(int i=0;i<n;i++){
        if(arr[i]==counter){
            counter++;
        }

        //skip negative number
        if(arr[i]<counter){
            continue;
        }

        //first missing positive number
        else{
            break;
        }
    }
    return counter;
}

int main(){
    int n;
    cout<<"Enter the size of the array you wnat to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The First Missing number is "<<firstMissing(arr,n)<<endl;

    return 0;
}