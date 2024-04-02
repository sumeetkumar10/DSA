#include<bits/stdc++.h>
using namespace std;

int countDistinct(int arr[],int n){
    unordered_set<int> s;

    int count=0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Number of distinct elements = "<<countDistinct(arr,n)<<endl;

    return 0;
}