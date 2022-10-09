#include <iostream>

using namespace std;

string dictionary[] = {"mobile","samsung","sam","sung", "man","mango", "icecream","and", "go","i","love","ice","cream"};

bool IsValidWord(string str){
    for(string word: dictionary){
        if(str == word){
            return true;
        }
    }
    return false;
}

void wordBreak(string iStr, int n, string result){
    for(int i=1; i<=n; i++){
        string prefix = iStr.substr(0, i);
        if(IsValidWord(prefix)){
            if(i==n){
                result = result + prefix;
                cout << result << endl;
                return;
            }
            wordBreak(iStr.substr(i), n-i, result+prefix+" ");
        }
    }
}

int main(){
    string str = "iloveicecreamandmango";

    wordBreak(str, str.length(), "");

    return 0;
}

