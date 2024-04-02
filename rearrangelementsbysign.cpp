#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeElements(vector<int>& arr,int n){
    vector<int> pos,neg;

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    for(int i=0;i<n;i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    return arr;
}

int main(){
    int n;
    cout<<"Enter the even size of the array you want to create"<<endl;
    cin>>n;

    vector<int> arr;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }

    vector<int> ans=rearrangeElements(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}