#include<iostream>
using namespace std;

bool CheckPalindrome(string str,int i){
    if(i>str.size()/2){
        return true;
    }

    return str[i]==str[str.size()-i-1] && CheckPalindrome(str,i+1);
}
int main()
{
    string name;

    cout<<"Enter you name ";
    getline(cin,name);

    cout<<"Your name is ";
    cout<<name<<endl;

    bool IsPalindrome=CheckPalindrome(name,0);

    if(IsPalindrome){
        cout<<"It is a palindrome"<<endl;
    }
    else{
        cout<<"It is not a palindrome"<<endl;
    }


    return 0;
}