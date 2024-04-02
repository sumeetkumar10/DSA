#include<iostream>
using namespace std;

int pairSum(int arr[],int n,int sum){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                count++;
            }
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

    int sum;
    cout<<"Enter the number"<<endl;
    cin>>sum;

    cout<<"Number of pairs with sum = "<<sum<<" is "<<pairSum(arr,n,sum)<<endl;

    return 0;
}