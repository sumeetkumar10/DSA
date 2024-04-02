#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

vector<int> nextSmaller(vector<int>& arr,int n){
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(st.top()!=-1 && arr[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int>& arr,int n){ 
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(st.top()!=-1 && arr[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

int areaOfLargestRectangularHistogram(vector<int>& heights){
    int n=heights.size();

    vector<int> next(n);
    next=nextSmaller(heights,n);

    vector<int> prev(n);
    prev=prevSmaller(heights,n);

    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int length=heights[i];

        if(next[i]==-1){
            next[i]=n;
        }
        int breadth=next[i]-prev[i]-1;
        
        int newArea=length*breadth;
        area=max(area,newArea);
    }
    return area;
}

int main(){
    vector<int> heights={2,1,5,6,2,3};

    cout<<"The Largest Area in the histogram is "<<areaOfLargestRectangularHistogram(heights)<<endl;

    return 0;
}