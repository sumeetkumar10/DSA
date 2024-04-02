#include<iostream>
#include<climits>
using namespace std;

int minSwaps(int arr[],int n,int k){
    int fav=0,nonFav=0;

    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            fav++;
        }
    }
    
    for(int i=0;i<fav;i++){
        if(arr[i]>k){
            nonFav++;
        }
    }

    int l=0,r=0,res=INT_MAX;

    while(r<n){
        res=min(res,nonFav);
        r++;
        if(r<n && arr[r]>k){
            nonFav++;
        }
        if(l<n && arr[l]>k){
            nonFav--;
        }
        l++;
    }
    return (res==INT_MAX)?0:res;
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

    cout<<"The minimum number of swaps to get "<<k<<" together is "<<minSwaps(arr,n,k)<<endl;

    return 0;
}