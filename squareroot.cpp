#include<iostream>
using namespace std;

long long int BinarySearch(long long int n){
    int start=0;
    int end=n;
    long long int ans=-1;

    while(start<=end){
        long long int mid=start+(end-start)/2;
        long long int square=mid*mid;

        if(square==n){
            return mid;
        }
        else if(square<n){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of which you want to find the square root"<<endl;
    cin>>n;

    cout<<"The square root of "<<n<<" is "<<BinarySearch(n)<<endl;

    return 0;
}