#include <iostream>

using namespace std;

string findReplaceSubString(string iStr, string X, string Y){
    int xLength = X.length();
    int sLength = iStr.length();
    for(int i=0; i+xLength<=sLength; i++){
        string curr = iStr.substr(i, xLength);
        if(curr==X || curr==Y){
            if (curr==X){
                iStr = iStr.substr(0,i) + Y + iStr.substr(i+xLength, sLength);
            } else if(curr==Y){
                iStr = iStr.substr(0,i) + X + iStr.substr(i+xLength, sLength);
            }
            i += xLength-1;
        }
    }
    return iStr;
}

int main(){
    string S="AAMBAA", X="AA", Y="BB";
    cout<<findReplaceSubString(S,X,Y);
    return 0;
}

