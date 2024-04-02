#include<iostream>
using namespace std;

int missingNumber(int arr[],int n){
    int d=(arr[n-1]-arr[0])/n;
    int missing=-1;

    for(int i=0;i<n;i++){
        int diff=arr[i+1]-arr[i];

        if(diff!=d){
            missing=arr[i]+d;
            break;
        }
    }
    return missing;
}

int main(){
    int arr[]={-1,5,8};

    cout<<"The missing number in the A.P. is "<<missingNumber(arr,3)<<endl;

    return 0;
}