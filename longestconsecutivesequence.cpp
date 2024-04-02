#include<iostream>
using namespace std;

bool linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int longestConsecutiveSequence(int arr[],int n){
    int longestLength=0;
    for(int i=0;i<n;i++){
        int currElement=arr[i];
        int currLength=1;
        while(linearSearch(arr,n,currElement+1)){
            currElement++;
            currLength++;
        }
        longestLength=max(longestLength,currLength);
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