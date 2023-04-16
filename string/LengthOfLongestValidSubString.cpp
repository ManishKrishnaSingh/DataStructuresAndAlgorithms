#include <bits/stdc++.h>

using namespace std;

int findMaxLength(string str){
    int maxLen = 0;

    stack<int> stk;

    stk.push(-1);
    for(int i=0; i < str.length(); i++){
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

int maxLengthValidSubstr(string str)
{
    int n = str.length();
    int index, left, right, maxLen=0;

    left = right = 0;
    // process from left to right
    for(index=0; index < n; index++)
    {
        if(str[index] == '(')
            left++;
        else
            right++;

        if(left == right)
        {
            maxLen = max(maxLen, 2*right);
        }
        else if(right > left)
        {
            left = right = 0;
        }
    }

    left = right = 0;
    // process from right to left
    for(index=n-1; index >= 0; index--)
    {
        if(str[index] == '(')
            left++;
        else
            right++;

        if(left == right)
        {
            maxLen = max(maxLen, 2*left);
        }
        else if(left > right)
        {
            left = right = 0;
        }
    }

    return maxLen;
}

int main(){
    string str = "())(()(()))))";

    int maxLength = findMaxLength(str);
    cout<<"Max Length[1] = "<<maxLength;

    int maxLen = maxLengthValidSubstr(str);
    cout<<"\n\n\nMax Length[2] = "<<maxLen;

    return 0;
}
