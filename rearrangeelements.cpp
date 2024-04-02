#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeElements(vector<int>& arr,int n){
    vector<int> neg,pos;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else if(arr[i]>0){
            pos.push_back(arr[i]);
        }
    }

    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index++]=pos[i];
        }
    }
    else{
        for(int i=0;i<pos.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            arr[index++]=neg[i];
        }
    }
    return arr;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int a;
    vector<int> arr;
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