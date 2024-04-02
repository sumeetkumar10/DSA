#include<iostream>
#include<algorithm>
using namespace std;

void printDistinct(int arr[],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(arr[i]==arr[j]){
                break;
            }
        }
        sort(arr,arr+n);
        if(i==j){
            cout<<arr[i]<<" ";
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

    cout<<"The distinct elements present in the array are:-"<<endl;
    printDistinct(arr,n);

    return 0;
}