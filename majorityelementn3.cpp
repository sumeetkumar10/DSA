#include<iostream>
#include<vector>
using namespace std;

vector<int> majorityElement(int arr[],int n){
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(ans.size()==0 || ans[0]!=arr[i]){
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }
            if(count>n/3){
                ans.push_back(arr[i]);
            }
        }
        if(ans.size()==2){
            break;
        }
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

    vector<int> ans=majorityElement(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}