#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

vector<int> nearestSmallerToLeft(int heights[],int n){
    vector<int> ans;
    stack<pair<int,int>> st;
    int pseudoIndex=-1;

    for(int i=0;i<n;i++){
        if(st.empty()){
            ans.push_back(pseudoIndex);
        }
        else if(st.size()>0 && st.top().first<heights[i]){
            ans.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first>=heights[i]){
            while(st.size()>0 && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(pseudoIndex);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push(make_pair(heights[i],i));
    }
    return ans;
}

vector<int> nearestSmallerToRight(int heights[],int n){
    vector<int> ans;
    stack<pair<int,int>> st;
    int pseudoIndex=n;

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans.push_back(pseudoIndex);
        }
        else if(st.size()>0 && st.top().first<heights[i]){
            ans.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first>=heights[i]){
            while(st.size()>0 && st.top().first>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(pseudoIndex);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push(make_pair(heights[i],i));
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int largestAreaInHistogram(int heights[],int n){
    vector<int> left=nearestSmallerToLeft(heights,n);
    vector<int> right=nearestSmallerToRight(heights,n);

    vector<int> width(n);
    int area=0;

    for(int i=0;i<n;i++){
        width[i]=right[i]-left[i]-1;
        area=max(area,width[i]*heights[i]);
    }
    return area;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* heights=new int[n];
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    cout<<"The largest rectangular area in the histogram is "<<largestAreaInHistogram(heights,n)<<endl;

    return 0;
}