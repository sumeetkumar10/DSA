#include<iostream>
using namespace std;

bool IsSorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }

    else{
        bool RemainingPart=IsSorted(arr+1,size-1);
        return RemainingPart;
    }
}
int main()
{
    int arr[5]={21,48,54,96,876};
    int size=5;

    bool ans=IsSorted(arr,size);

    if(ans){
        cout<<"Yes! the array is sorted"<<endl;
    }

    else{
        cout<<"The array is not sorted"<<endl;
    }
    
    return 0;
}