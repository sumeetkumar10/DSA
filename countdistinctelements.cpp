#include<iostream>
using namespace std;

int countDistinct(int arr[],int n){
    int count=0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
        //for(int j=0;j<i;j++)
            if(arr[i]==arr[j]){
                break;
            }
        }
        if(arr[i]!=arr[j]){
            count++;
        }
        //if(i==j){
        //    count++;
        //}
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

    cout<<"Number of distinct elements in the array are "<<countDistinct(arr,n)<<endl;

    return 0;
}