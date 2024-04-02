#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(string str,int index,string result,vector<string>& ans){
    if(index==str.length()){
        ans.push_back(result);
        return ;
    }

    printSubsequences(str,index+1,result+str[index],ans);
    printSubsequences(str,index+1,result,ans);
}

int main(){
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);

    vector<string> ans;
    printSubsequences(str,0,"",ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}