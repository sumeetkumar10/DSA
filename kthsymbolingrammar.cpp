#include<iostream>
using namespace std;

int kthGrammar(int n,int k){
    if(n==1){
        return 0;
    }

    int parent=kthGrammar(n-1,k/2+k%2);

    if(parent==0){
        if(k&1){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if(k&1){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    cout<<k<<" th symbol in the grammar is "<<kthGrammar(n,k)<<endl;

    return 0;
}