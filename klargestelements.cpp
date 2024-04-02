#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> kLargest(int arr[],int n,int k){
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
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

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    vector<int> ans=kLargest(arr,n,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}