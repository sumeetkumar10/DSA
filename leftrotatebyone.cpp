#include<iostream>
#include<vector>
using namespace std;

vector<int> leftRotateByOne(int arr[],int n){
    vector<int> ans;
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
        ans.push_back(arr[i]);
    }
    arr[n-1]=temp;
    ans.push_back(temp);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the sizse of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans=leftRotateByOne(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}