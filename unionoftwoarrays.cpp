#include<iostream>
#include<set>
#include<vector>
using namespace std;

vector<int> unionOfTwoArrays(int arr1[],int arr2[],int n,int m){
    vector<int> ans;
    set<int> set;

    for(int i=0;i<n;i++){
        set.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        set.insert(arr2[i]);
    }

    for(auto it:set){
        ans.push_back(it);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the first array"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the size of the second array"<<endl;
    cin>>m;

    int* arr1=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    int* arr2=new int[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    vector<int> ans=unionOfTwoArrays(arr1,arr2,n,m);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}