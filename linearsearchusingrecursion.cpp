#include<iostream>
using namespace std;

bool LinearSearch(int arr[],int n,int key){
    if(n==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }

    else{
        bool RemainingPart=LinearSearch(arr+1,n-1,key);
        return RemainingPart;
    }
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

    int key;
    cout<<"Enter the number you want to esrach in the array"<<endl;
    cin>>key;

    bool ans=LinearSearch(arr,n,key);

    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
        
    }


    return 0;
}