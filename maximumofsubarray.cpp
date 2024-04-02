#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> maxOfSubarrays(int arr[],int n,int k){
    vector<int> ans;
    deque<int> dq;

    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        if(i>=k-1){
            ans.push_back(arr[dq.front()]);
        }
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

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    vector<int> ans=maxOfSubarrays(arr,n,k);

    cout<<"The vector of the maximum of All the Subarrays of size "<<k<<" is:- ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}