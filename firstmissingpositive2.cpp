#include<iostream>
using namespace std;

int firstMissing(int arr[],int n){
    bool visited[n+2]={false};

    for(int i=0;i<n;i++){
        if(arr[i]>=0 && arr[i]<=n){
            visited[arr[i]]=true;
        }
    }

    for(int i=1;i<n+2;i++){
        if(!visited[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;
    
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The first missing number is "<<firstMissing(arr,n)<<endl;

    return 0;
}