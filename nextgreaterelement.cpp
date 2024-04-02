#include<iostream>
using namespace std;

void printNGE(int arr[],int n){
    int next,i,j;
    for(i=0;i<n;i++){
        next=-1;
        for(j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                next=arr[j];
                break;
            }
        }
        cout<<arr[i]<<"--"<<next<<endl;
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

    printNGE(arr,n);

    return 0;
}