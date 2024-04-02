#include<iostream>
#include<vector>
using namespace std;

vector<int> pascalTriangle(int n){
    vector<int> ans;
    int res=1;
    ans.push_back(res);

    for(int i=1;i<n;i++){
        res*=(n-i);
        res/=i;
        ans.push_back(res);
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