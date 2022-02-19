#include <iostream>

using namespace std;

string findLongestEvenLengthWord(string iStr){
    int curLength = 0;
    int maxLength = 0;
    int startIndex = -1;

    int idx = 0;
    while(idx < iStr.length()) {
        if(iStr[idx]==' ') {
            if(curLength%2 == 0) {
                if(maxLength < curLength) {
                    maxLength = curLength;
                    startIndex = idx-curLength;
                }
            }
            curLength = 0;
        } else {
            curLength++;
        }
        idx++;
    }

    // length of last word.
    if (curLength%2 == 0) {
        if (maxLength < curLength) {
            maxLength = curLength;
            startIndex = idx-curLength;
        }
    }
    if (startIndex == -1){
        return "-1";
    }
    return iStr.substr(startIndex, maxLength);
}

int main(){
    string str = "always create a positive environment";
    cout<<"Longest word = "<<findLongestEvenLengthWord(str);
    return 0;
}

