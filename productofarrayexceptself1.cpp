#include<iostream>
#include<vector>
using namespace std;

int multiply(int a, int b)
{
    int mod = 1e9 + 7;
    long long ret = a % mod;
    ret *= (b % mod);
    ret = ret % mod;
    return ret;
}

void getProductArrayExceptSelf(int *arr, int n)
{
    int *output = new int[n];
    int product = 1;

    for (int i = 0; i < n; ++i) 
    {
        output[i] = product;
        product = multiply(product, arr[i]);
    }

    product = 1;

    for (int i = n - 1; i >= 0; --i) 
    {
        output[i] = multiply(product, output[i]);
        product = multiply(product, arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    getProductArrayExceptSelf(arr,n);
    
    return 0;
}