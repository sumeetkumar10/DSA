#include<iostream>
#include<climits>
using namespace std;

int maximumSumSubarray(int K, int arr[] , int N){
        // long long maxi=INT_MIN;
        
        // for(int i=0;i<N-K+1;i++){
        //     long long currSum=0;
        //     for(int j=0;j<K;j++){
        //         currSum+=Arr[i+j];
        //     }
        //     maxi=max(currSum,maxi);
        // }
        // return maxi;
        
        int i=0,j=0;
        int sum=0;
        int maxi=INT_MIN;
        
        while(j<N){
            sum+=arr[j];
            
            if(j-i+1<K){
                j++;
            }
            else if(j-i+1==K){
                maxi=max(maxi,sum);
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return maxi;
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

    cout<<"The maximum sum subarray of size "<<k<<" is "<<maximumSumSubarray(k,arr,n);

    return 0;
}