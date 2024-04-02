#include<iostream>
using namespace std;

bool isPresent(int arr[][4],int row,int col,int target){
    int start=0;
    int end=row*col-1;

    int mid=start+(end-start)/2;

    while(start<=end){
        
        int element=arr[mid/col][mid%col];

        if(element==target){
            return 1;
        }
        else if(element>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return 0;
}

int main(){
    int arr[3][4];

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cin>>arr[3][3];
        }
    }

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<arr[3][3]<<" ";
        }
        cout<<endl;
    }

    int key;
    cout<<"Enter the number you want to search in the 2d array"<<endl;
    cin>>key;
    
    return 0;
}