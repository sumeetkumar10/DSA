#include<iostream>
#include<vector>
using namespace std;

int firstIndex(int arr[],int n,int index,int target){
    if(index==n){
        return -1;
    }

    if(arr[index]==target){
        return index;
    }
    else{
        return firstIndex(arr,n,index+1,target);
    }
}

void findAllOccurrence(int arr[],int n,int index,int target,vector<int>& ans){
    if(index==n){
        return ;
    }

    if(arr[index]==target){
        ans.push_back(index);
    }

    return findAllOccurrence(arr,n,index+1,target,ans);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the number which you want to search in the array"<<endl;
    cin>>target;

    cout<<"The first occurrence of "<<target<<" in the array is at "<<firstIndex(arr,n,0,target)<<" index."<<endl;

    vector<int> ans;
    findAllOccurrence(arr,n,0,target,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}