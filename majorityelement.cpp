#include<iostream>
#include<map>
using namespace std;

int majorityElement(int arr[],int n){
    map<int,int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }

    for(auto it:map){
        if(it.second>n/2){
            return it.first;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The majority element in the array is "<<majorityElement(arr,n)<<endl;

    return 0;
}