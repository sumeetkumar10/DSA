#include<iostream>
using namespace std;

int GetSum(int arr[],int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }

    return arr[0]+GetSum(arr+1,n-1);

}
int main()
{
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The sum of all the elements in the array is "<<GetSum(arr,n)<<endl;


    return 0;
}

