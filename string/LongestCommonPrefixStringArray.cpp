#include <iostream>
#include <algorithm>

using namespace std;

string findLongestCommonPrefix(string words[], int n){
    sort(words, words+n);

    string firstWord = words[0];
    string lastWord  = words[n-1];

    int minLength = min(firstWord.length(), lastWord.length());

    int idx = 0;
    while(idx<minLength && firstWord[idx] == lastWord[idx]){
        idx++;
    }

    return firstWord.substr(0, idx);
}

int main(){
    string words[] = {"apple", "ape", "april"};
    int n = sizeof(words) / sizeof(words[0]);

    string str=findLongestCommonPrefix(words,n);
    cout<<"Longest Common Prefix = "<<str<<endl;

    return 0;
}

