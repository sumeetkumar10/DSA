#include<iostream>
using namespace std;

struct Pair{
    int Max;
    int Min;
};

struct Pair getMinMax(int arr[],int n){
    struct Pair MinMax;

    if(n==1){
        MinMax.Max=arr[0];
        MinMax.Min=arr[0];
        return MinMax;
    } 

    if(arr[0]>arr[1]){
        MinMax.Max=arr[0];
        MinMax.Min=arr[1];
    }

    if(arr[1]>arr[0]){
        MinMax.Max=arr[1];
        MinMax.Min=arr[0];
    }

    for(int i=2;i<n;i++){
        if(arr[i]>MinMax.Max){
            MinMax.Max=arr[i];
        }
        if(arr[i]<MinMax.Min){
            MinMax.Min=arr[i];
        }
    }
    return MinMax;
};

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    struct Pair MinMax=getMinMax(arr,n);

    cout<<"The Maximum number present in the array is "<<MinMax.Max<<endl;
    cout<<"The Minimum number present in the array is "<<MinMax.Min<<endl;

    cout<<"The Sum of Maximum and Minimum number of the array is "<<MinMax.Max+MinMax.Min<<endl;

    return 0;
}