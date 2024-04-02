#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

int longestConsecutiveSequence(int arr[],int n){
    unordered_set<int> H;
    for(int i=0;i<n;i++){
        H.insert(arr[i]);
    }

    int longestLength=0;
    for(int i=0;i<n;i++){
        if(H.find(arr[i]-1)==H.end()){
            int currElement=arr[i];
            int currLength=1;
            while(H.find(currElement+1)!=H.end()){
                currElement++;
                currLength++;
            }
            longestLength=max(currLength,longestLength);
        }
    }
    return longestLength;
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