#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeElements(vector<int>& arr,int n){
    vector<int> even,odd;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even.push_back(arr[i]);
        }
        else if(arr[i]%2!=0){
            odd.push_back(arr[i]);
        }
    }

    if(odd.size()>even.size()){
        for(int i=0;i<even.size();i++){
            arr[2*i]=odd[i];
            arr[2*i+1]=even[i];
        }
        int index=even.size()*2;
        for(int i=even.size();i<odd.size();i++){
            arr[index++]=odd[i];
        }
    }
    else{
        for(int i=0;i<odd.size();i++){
            arr[2*i]=odd[i];
            arr[2*i+1]=even[i];
        }
        int index=odd.size()*2;
        for(int i=odd.size();i<even.size();i++){
            arr[index++]=even[i];
        }
    }
    return arr;
}

int main(){
    vector<int> arr={3,2,6,1,5,7,12,9};
    int n=7;

    vector<int> ans=rearrangeElements(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}