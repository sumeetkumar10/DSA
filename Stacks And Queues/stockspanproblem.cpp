#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> calculateSpan(int price[],int n){
    vector<int> ans;
    stack<pair<int,int>> st;

    //Use the concept of "Next Greater Element on left"
    for(int i=0;i<n;i++){
        if(st.empty()){
            ans.push_back(-1);
        }
        else if(st.size()>0 && st.top().first>price[i]){
            ans.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first<=price[i]){
            while(st.size()>0 && st.top().first<=price[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push(make_pair(price[i],i));
    }

    for(int i=0;i<n;i++){
        ans[i]=i-ans[i];
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* price=new int[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    vector<int> ans=calculateSpan(price,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}