#include<iostream>
#include<climits>
using namespace std;

int maxProfitSneakers(int arr[],int n){
    int maxi=INT_MIN;
    
    for(int i=0;i<n;i++){
        int res1=0,res2=0;
        for(int j=i+1;j<n;j++){
            int orr=arr[i]|arr[j];
            int andd=arr[i]&arr[j];

            res1=orr*orr;
            res2=andd*andd;
        }
    }
}

int main(){


    return 0;
}