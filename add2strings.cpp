#include<iostream>
#include<algorithm>
using namespace std;

void add2Strings(string a,string b,int carry,string& ans,int i,int j){
    if(i<0 && j<0 && carry==0){
        return ;
    }

    int first=0;
    int second=0;
    
    if(i>=0){
        first=a[i]-'0';
    }
    if(j>=0){
        second=b[j]-'0';
    }

    int sum=first+second+carry;
    int lastDigit=sum%10;
    carry=sum/10;

    ans.push_back(lastDigit+'0');
    add2Strings(a,b,carry,ans,i-1,j-1);
}

int main(){
    string a="987";
    string b="12";

    string ans="";
    add2Strings(a,b,0,ans,a.length()-1,b.length()-1);
    reverse(ans.begin(),ans.end());
    cout<<"Sum is "<<ans<<endl;

    return 0;
}