#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(int n){
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

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;

    for(int i=1;i<=n;i++){
        ans.push_back(solve(n));
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the row number"<<endl;
    cin>>n;

    

    return 0;
}