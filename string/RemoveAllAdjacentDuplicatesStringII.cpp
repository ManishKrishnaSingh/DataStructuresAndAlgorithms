#include <bits/stdc++.h>

using namespace std;

/******************************************
Remove All Adjacent Duplicates in String II
******************************************/

string removeDuplicates(string iStr, int K){
    string result = "";

    if(!iStr.empty() and K > 0){
        stack<pair<char,int>> stk;
        for(int i=0; i<iStr.length(); i++){
            // add if stack is empty or if its a new char
            if(stk.empty() || stk.top().first != iStr[i]){
                stk.push({iStr[i], 1});
            } else {
                // increase count
                stk.top().second++;
                // delete char on count 3
                if(stk.top().second == K)
                {
                    stk.pop();
                }
            }
        }

        // build response
        while(!stk.empty()){
            while(stk.top().second--){
                result = stk.top().first + result;
            }
            stk.pop();
        }
    }

    return result;
}

int main() {
    cout<<"["<<removeDuplicates("aabcdd",2)<<"]\n";
    cout<<"["<<removeDuplicates("deeedbbcccbdaa",3)<<"]\n";
    cout<<"["<<removeDuplicates("pbbcggttciiippooaais",2)<<"]\n";
    return 0;
}