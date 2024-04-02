#include<iostream>
using namespace std;

// void ReverseString(string &str,int i,int j){                     
//     if(i>j){
//         return ;
//     }
//     swap(str[i],str[j]);
//     i++;
//     j--;

//     ReverseString(str,i,j);
// }

string ReverseString(string str){
    if(str.length()<=1){
        return str;
    }

    return ReverseString(str.substr(1))+str[0];
}

int main()
{
    string name;

    cout<<"Enter you name ";
    getline(cin,name);

    cout<<"Your name is ";
    cout<<name<<endl;
    
    // ReverseString(name,0,name.length()-1);
    // for(int i=name.length()-1;i>=0;i--){
    //     cout<<name[i];
    // }
    cout<<"The reversed string is ";
    cout<<ReverseString(name)<<endl;


    return 0;
}