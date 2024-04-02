#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n){
    vector<int> ans;
    stack<int> s;
    
    for(int i=arr.size()-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

    vector<int> answer={4,2,5,9,1,3};

    vector<int> answer1= nextGreaterElement(answer,6);

    cout<<"Original Array is "<<endl;

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    cout<<endl;

    cout<<"The array of next greater element is "<<endl;

    for(int i=0;i<answer.size();i++){
        cout<<answer1[i]<<" ";
    }

    return 0;
}