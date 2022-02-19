#include <bits/stdc++.h>

using namespace std;

int minParentheses(string iStr){
    stack<char> stk;

    int n = iStr.length();
    for(int i=0; i<n; i++){
        if(iStr[i] == '(' || stk.empty()){
            stk.push(iStr[i]);
        } else if(stk.top() == '(' && iStr[i] == ')'){
            stk.pop();
        }
    }

    return stk.size();
}

int main(){
    string str = "((())()";

    int result = minParentheses(str);
    cout<<"Minimum Parentheses = "<<result<<endl;

    return 0;
}

