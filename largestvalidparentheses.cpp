#include<iostream>
#include<stack>
using namespace std;

int longestValidParentheses(string expression){
    stack<int> st;
    st.push(-1);
    int maxi=0;

    for(int i=0;i<expression.length();i++){
        if(expression[i]=='('){
            st.push(i);
        }
        if(expression[i]==')'){
            st.pop();

            if(st.empty()){
                st.push(i);
            }
            else{
                maxi=max(maxi,i-st.top());
            }
        }
    }
    return maxi;
}

int main(){
    string expression=")()(()))";

    cout<<"The longest Valid Parentheses in the string is "<<longestValidParentheses(expression)<<endl;

    return 0;
}