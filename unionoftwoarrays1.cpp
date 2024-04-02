#include<iostream>
#include<vector>
using namespace std;

vector<int> unionOfTwoArrays(int arr1[],int arr2[],int n,int m){
    vector<int> ans;
    int i=0,j=0;

    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n){
        if(ans.size()==0 || ans.back()!=arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while(j<m){
        if(ans.size()==0 || ans.back()!=arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
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