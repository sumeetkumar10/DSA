#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmaller(int arr[],int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(!st.empty() && st.top()>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
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

    vector<int> ans=nextSmaller(arr,n);
    int size=ans.size();
    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}