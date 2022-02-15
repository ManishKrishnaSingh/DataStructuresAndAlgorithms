#include <iostream>

using namespace std;

string removeDuplicates(string iStr) {
    string oStr="";
    int hash[256] = {0};
    for(auto c : iStr){
        int idx = (int)c;
        if(hash[idx] == 0){
            oStr += c;
            hash[idx]++;
        }
    }
    return oStr;
}

int main(){
    string str = "asdfsfdssdad";

    string uniqChars = removeDuplicates(str);
    cout<<"Unique Chars = "<<uniqChars<<endl;

    return 0;
}

