#include <stack>
#include <climits>
#include <iostream>

using namespace std;

int findMaxLength(string str){
    int n = str.length();
    int maxLen = INT_MIN;

    stack<int> stk;
    stk.push(-1);

    for(int i=0; i<n; i++){
        if(str[i] == '('){
            stk.push(i);
        } else {
            if(!stk.empty()){
                stk.pop();
            }

            if(!stk.empty()){
                maxLen = max(maxLen, i-stk.top());
            } else {
                stk.push(i);
            }
        }
    }

    return maxLen;
}

int main(){
    string str = "())(()(()))))";

    int maxLength = findMaxLength(str);
    cout<<"Max Length = "<<maxLength<<endl;

    return 0;
}

