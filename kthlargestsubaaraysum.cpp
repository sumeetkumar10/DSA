#include<iostream>
#include<queue>
using namespace std;

int getkthLargest(int arr[],int k,int n){
    priority_queue<int,vector<int>,greater<int>> mini;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    cout<<k<<" th largest subarary sum in the array is "<<getkthLargest(arr,k,n)<<endl;

    return 0;
}