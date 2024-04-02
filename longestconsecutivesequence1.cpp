#include<iostream>
#include<algorithm>
using namespace std;

int longestConsecutiveSequence(int arr[],int n){
    sort(arr,arr+n);

    int longestLength=0;
    int currLength=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            if(arr[i]==arr[i-1]+1){
                currLength++;
            }
            else{
                longestLength=max(currLength,longestLength);
                currLength=1;
            }
        }
    }
    return max(currLength,longestLength);
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The longest consecutive sequence in the array is "<<longestConsecutiveSequence(arr,n)<<endl;

    return 0;
}