#include<iostream>
using namespace std;

void printSubsequences(string str,int index,string ans){
    if(index==str.length()){
        cout<<ans<<endl;
        return ;
    }

    //include
    printSubsequences(str,index+1,ans+str[index]);
    //exclude
    printSubsequences(str,index+1,ans);
}

int main(){
    string str="12345";
    
    string ans="";

    printSubsequences(str,0,ans);

    return 0;
}