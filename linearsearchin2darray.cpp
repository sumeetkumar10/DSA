#include<iostream>
using namespace std;

bool isPresent(int arr[][3],int key,int row,int col){
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(arr[row][col]==key){
                cout<<row<<" "<<col<<endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[3][3];

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cin>>arr[row][col];
        }
    }

    cout<<"The matrix is "<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    int key;
    cout<<"Enter the number you want to search in the 2d array"<<endl;
    cin>>key;

    if(isPresent(arr,key,3,3)){
        cout<<"Element is found"<<endl;

    }
    else{
        cout<<"Element is not found"<<endl;

    }

    return 0;
}