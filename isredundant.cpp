#include<iostream>
#include<stack>
using namespace std;

bool isRedundantBrackets(string& expression){
    stack<char> st;

    for(int i=0;i<expression.length();i++){
        char ch=expression[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;

                while(st.top()!='('){
                    char top=st.top();

                    if(top=='+' || top=='-' || top=='*' || top=='/'){
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant==true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string expression="(a+b)*(c-d)/(e+f))";

    if(isRedundantBrackets(expression)){
        cout<<"There is Redundant Bracket."<<endl;
    }
    else{
        cout<<"There is no Redundant Bracket."<<endl;
    }

    return 0;
}