#include <vector>
#include <iostream>

using namespace std;

vector<string> dictionary = {"ale", "apple", "monkey", "plea"};

bool isSubsequence(string str, string word){
    int sLen = str.length();
    int wLen = word.length();

    int i=0, j=0;
    for(; i<sLen && j<wLen; i++){
        if(str[i] == word[j]){
            j++;
        }
    }
    return (j == wLen);
}

string findLongestString(string str){
    string result = "";
    int maxLength = 0;

    for(string word : dictionary){
        if((word.length() > maxLength) && isSubsequence(str, word)){
            result = word;
            maxLength = word.length();
        }
    }

    return result;
}

int main(){
    string strLongest = findLongestString("abpcplea");
    cout << "Longest string = " << strLongest << endl;

    return 0;
}

