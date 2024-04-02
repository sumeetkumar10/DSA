#include<iostream>
#include<queue>
using namespace std;

int kthSmallest(int arr[],int n,int k){
    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
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

    cout<<k<<" th smallest element in the array is "<<kthSmallest(arr,n,k)<<endl;

    return 0;
}