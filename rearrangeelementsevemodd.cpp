#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeElements(vector<int>& arr,int n){
    vector<int> even,odd;

    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even.push_back(arr[i]);
        }
        else{
            odd.push_back(arr[i]);
        }
    }

    for(int i=0;i<n;i++){
        arr[2*i]=even[i];
        arr[2*i+1]=odd[i];
    }
    return arr;
}

int main(){
    vector<int> arr={3,2,6,1,5,96};
    int n=6;

    vector<int> ans=rearrangeElements(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}