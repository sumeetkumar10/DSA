#include<iostream>
using namespace std;

int majorityElement(int arr[],int n){
    int count=0,element;
    for(int i=0;i<n;i++){
        if(count==0){
            count=1;
            element=arr[i];
        }
        else if(arr[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
    
    int count1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            count1++;
        }
    }
    if(count1>n/2){
        return element;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of teh array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The majority element in the array is "<<majorityElement(arr,n)<<endl;

    return 0;
}