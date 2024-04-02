#include<iostream>
using namespace std;

void firstNegativeInteger(int arr[],int n,int k){
    bool flag;
    for(int i=0;i<(n-k+1);i++){
        flag=false;
        for(int j=0;j<k;j++){
            if(arr[i+j]<0){
                cout<<arr[i+j]<<" ";
                flag=true;
                break;
            }
        }
    }
    if(!flag){
        cout<<"0"<<" ";
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

    int k;
    cin>>k;

    firstNegativeInteger(arr,n,k);

    return 0;
}