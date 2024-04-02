#include<iostream>
#include<vector>
using namespace std;

int findnCr(int n,int r){
    int ans=1;
    for(int i=0;i<r;i++){
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}

vector<int> pascalTriangle(int n){
    vector<int> ans;
    for(int c=1;c<=n;c++){
        ans.push_back(findnCr(n-1,c-1));
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the row number"<<endl;
    cin>>n;

    vector<int> ans=pascalTriangle(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}