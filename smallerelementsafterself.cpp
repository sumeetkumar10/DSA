#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& count,vector<pair<int,int>>& ans,int left,int mid,int right){
    vector<pair<int,int>> temp(right-left+1);
    int i=left;
    int j=mid+1;
    int k=0;

    while(i<=mid && j<=right){
        if(ans[i].first<=ans[j].first){
            temp[k++]=ans[j++];
        }
        else{
            count[ans[i].second]+=right-j+1;
            temp[k++]=ans[i++];
        }
    }
    while(i<=mid){
        temp[k++]=ans[i++];
    }
    while(j<=right){
        temp[k++]=ans[j++];
    }

    for(int i=left;i<=right;i++){
        ans[i]=temp[i-left];
    }
}

void mergeSort(vector<int>& count,vector<pair<int,int>>& ans,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(count,ans,left,mid);
        mergeSort(count,ans,mid+1,right);
        merge(count,ans,left,mid,right);
    }
}

vector<int> countSmaller(vector<int>& arr){
    int n=arr.size();
    vector<int> count(n,0);
    vector<pair<int,int>> ans(n);

    for(int i=0;i<n;i++){
        pair<int,int> p;
        p.first=arr[i];
        p.second=i;
        ans[i]=p;
    }

    mergeSort(count,ans,0,n-1);
    return count;
}

int main(){
    vector<int> arr={6,5,4,3,8,9};

    vector<int> ans=countSmaller(arr);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}