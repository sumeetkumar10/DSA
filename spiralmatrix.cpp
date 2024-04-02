#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(int matrix[][3],int n,int m){
    int top=0,bottom=n-1;
    int left=0,right=m-1;

    vector<int> ans;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans=spiralMatrix(matrix,3,3);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}