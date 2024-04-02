#include<iostream>
using namespace std;

string removeOccurrence(string str,int index,int n,char ch){
    if(index==n){
        return "";
    }

    string curr="";
    curr+=str[index];
    return (str[index]==ch?"":curr)+removeOccurrence(str,index+1,n,ch);
}

int main(){
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);

    char ch;
    cout<<"Enter the character which you want to remove from the string"<<endl;
    cin>>ch;

    cout<<"The string obtained after removeing all the occurrence of "<<ch<<" is "<<removeOccurrence(str,0,str.length(),ch);

    return 0;
}