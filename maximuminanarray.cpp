#include<iostream>
#include<climits>
using namespace std;

int getMax(int arr[],int n,int index){
    if(index==n){
        return INT_MIN;
    }

    int ans=arr[index];
    int recAns=getMax(arr,n,index+1);

    return max(ans,recAns);
}

void maximumElement(int arr[],int n,int index,int& maxi){
    if(n==index){
        return ;
    }

    maxi=max(maxi,arr[index]);

    maximumElement(arr,n,index+1,maxi);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The maximum number in the array is "<<getMax(arr,n,0)<<endl;

    int maxi=INT_MIN;
    maximumElement(arr,n,0,maxi);
    cout<<"The maximum number in the array is "<<maxi<<endl;

    return 0;
}