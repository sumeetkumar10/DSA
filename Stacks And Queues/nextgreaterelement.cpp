#include<iostream>
#include<vector>
using namespace std;

vector<int> printNGE(int arr[],int n){
    int next,i,j;
    vector<int> ans;

    for(int i=0;i<n;i++){
        next=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                next=arr[j];
                break;
            }
        }
        ans.push_back(next);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans=printNGE(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}