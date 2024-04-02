#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
#define N 4
#define M 4

vector<int> nextSmaller(int arr[],int n){
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

vector<int> prevSmaller(int arr[],int n){
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

int largestHistogram(int heights[],int n){
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

int maxRectangle(int matrix[N][M],int n,int m){
    int area=largestHistogram(matrix[0],m);

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=matrix[i][j]+matrix[i-1][j];
            }
            else{
                matrix[i][j]=0;
            }
        }
        area=max(area,largestHistogram(matrix[i],m));
    }
    return area;
}

int main(){
    int n=4;
    int m=4;

    int matrix[N][M]={{0, 1, 1, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {1, 1, 0, 0}};

    cout<<"The Largest Rectangle is "<<maxRectangle(matrix,4,4)<<endl;

    return 0;
}