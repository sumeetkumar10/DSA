#include<iostream>
using namespace std;

void moveNegative(int arr[],int left,int right){
    while(left<=right){
        if(arr[left]<0 && arr[right]<0){
            left++;
        }

        else if(arr[left]>0 && arr[right]<0){
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }

        else if(arr[left]>0 && arr[right]>0){
            right--;
        }

        else{
            left++;
            right--;
        }
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    moveNegative(arr,0,n);
    printArray(arr,n);

    return 0;
}