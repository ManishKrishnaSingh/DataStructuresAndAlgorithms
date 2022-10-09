#include <bits/stdc++.h>

using namespace std;

string removeKdigits(string iStr, int K){
    stack<char> stk;
    for(int i=0; i<iStr.size(); i++){
        // remove largest most values from left side
        while(K>0 && !stk.empty() && stk.top()>iStr[i]){
            stk.pop(); K--;
        }

        stk.push(iStr[i]); // add to the stack
    }

    // remove the largest values
    while(K > 0 && !stk.empty()){
        stk.pop(); K--;
    }

    if(!stk.empty()){
        string minStr = "";
        while (!stk.empty()) {
            minStr = stk.top()+minStr; stk.pop();
        }
        // stripping the leadnig zeros
        return to_string(stoi(minStr));
    }

    return "0";
}

int main(){
    string str = "1432219";
    cout<<removeKdigits(str,3);
    return 0;
}
