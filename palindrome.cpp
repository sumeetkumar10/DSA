#include<iostream>
using namespace std;

bool CheckPalindrome(string str,int i,int j){               
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return CheckPalindrome(str,i+1,j-1);
    }
}

int main()
{
    string name;

    cout<<"Enter you name ";
    getline(cin,name);

    cout<<"Your name is ";
    cout<<name<<endl;

    bool IsPalindrome=CheckPalindrome(name,0,name.length()-1);

    if(IsPalindrome){
        cout<<"It is a palindrome"<<endl;
    }
    else{
        cout<<"It is not a palindrome"<<endl;
    }

    return 0;
}