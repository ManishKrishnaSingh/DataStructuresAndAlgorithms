#include <bits/stdc++.h>

using namespace std;

string generate(string iStr){
    string result = "";

    int sLength = iStr.length();
    unordered_map<char,int> mCount;

    mCount[iStr[0]]++;
    for(int i=1; i<=sLength; i++) {
        if(mCount.find(iStr[i])==mCount.end()) {
            auto prev = mCount.find(iStr[i-1]);
            result += to_string(prev->second)+prev->first;
            mCount.clear();
        }
        mCount[iStr[i]]++;
    }

    return result;
}

void LookAndSay(int n){
    string number = "1";
    cout<<"-> "<<number<<endl;

    for(int i=1; i<n; i++) {
        number = generate(number);
        cout<<"-> "<<number<<endl;
    }
}

int main(){
    LookAndSay(5);

    return 0;
}

