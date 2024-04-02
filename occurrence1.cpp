#include<iostream>
using namespace std;

void firstAndLast(int arr[],int n,int key){
    int first=-1;
    int last=-1;

    for(int i=0;i<n;i++){
        if(arr[i]!=key){
            continue;
        }
        if(first==-1){
            first=i;
        }
        last=i;
    }
    if(first!=-1){
        cout<<"The first occurrence of "<<n<<" in the array is "<<first<<endl;
        cout<<"The last occurrence of "<<n<<" in the array is "<<last<<endl;
    }
    else{
        cout<<"Not! Found"<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the number you want to search in the array"<<endl;
    cin>>key;

    firstAndLast(arr,n,key);

    return 0;
}