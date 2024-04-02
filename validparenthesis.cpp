#include<iostream>
#include<stack>
using namespace std;

bool isValidParentheses(string& expression){
    stack<char> st;

    for(int i=0;i<expression.length();i++){
        char ch=expression[i];

        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char top=st.top();

                if((top=='(' && ch==')') || (top=='{' && ch=='}') ||(top=='[' && ch==']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string expression="(((({[[]]}))))";

    if(isValidParentheses(expression)){
        cout<<"It is a Valid Parentheses."<<endl;
    }
    else{
        cout<<"It is not a Valid Parentheses."<<endl;
    }

    return 0;
}