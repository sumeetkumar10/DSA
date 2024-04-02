#include<iostream>
using namespace std;

int solve(int cost[],int n){
    int prev2=cost[0];
    int prev1=cost[1];

    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}

int minCostClimbingStairs(int arr[],int n){
    return solve(arr,n);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* cost=new int[n];
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    cout<<"The minimum cost of climbing the stairs is "<<minCostClimbingStairs(cost,n)<<endl;

    return 0;
}