#include <climits>
#include <iostream>

using namespace std;

typedef struct window{
    int beg;
    int end;
    window(int b, int e){
        beg = b;
        end = e;
    }
}window;

window minWindow(string iStr, string iTxt){
    window window(-1, -1);
    int minLength = INT_MAX;

    int sLength = iStr.length();
    int tLength = iTxt.length();

    if(sLength >= tLength){
        int mTxt[256] = {0};
        int mStr[256] = {0};

        for(char c : iTxt){
            mTxt[c]++;
        }

        int i=0, j, count=0;
        for(int j=0; j<iStr.length(); j++){
            mStr[iStr[j]]++;

            if(mTxt[iStr[j]] >= mStr[iStr[j]]){
                count++;
            }

            if(count == tLength){
                while(mStr[iStr[i]] > mTxt[iStr[i]]){
                    mStr[iStr[i++]]--;
                }

                int length = j-i+1;
                if(minLength > length){
                    window.beg = i;
                    window.end = j;
                    minLength = length;
                }
            }
        }
    }

    return window;
}

int main(){
    string str = "ADOBECODEBANC";
    string text = "ABC";

    window w = minWindow(str, text);
    cout<<"Smallest window : ["<<w.beg<<"-"<<w.end<<"]"<<endl;
    string minWinString = str.substr(w.beg, w.end - w.beg + 1);
    cout<<"Smallest window : ["<<minWinString<<"]"<<endl;

    return 0;
}

