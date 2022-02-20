#include <cmath>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string iStr){
    vector<string> op;
    string word;
    stringstream ss(iStr);
    while(ss >> word){
        op.push_back(word);
    }
    return op;
}

string justifyLine(string iStr, int L){
    if(iStr.length() == L){
        return iStr;
    }

    vector<string> words = split(iStr);

    // Just 1 Word
    if(words.size() == 1){
        return iStr;
    }

    // Apply Spaces
    int noOfWords = words.size();
    int xtraSpace = L-iStr.length();
    int xtraSpaceByWord = ceil(xtraSpace/(noOfWords-1));

    int i=1;
    string str = words[0];
    while(i<noOfWords){
        if(xtraSpace>0){
            int nSpace=xtraSpaceByWord;
            while(nSpace>0){
                str += " ";
                nSpace--;
                xtraSpace--;
            }
        }
        str = str +" " +words[i];
        i++;
    }
    return str;
}

void justifyText(string iStr, int L){
    vector<string> words = split(iStr);;

    //Apply length
    int i=0,j=i+1;
    while(j<words.size()){
        string str = words[i]+" "+words[j];
        if(str.length()>L){
            i=j;
        } else {
            words[i] = str;
            words[j] = "";
        }
        j++;
    }

    //Justify Non-empty Lines
    for(string line : words){
        if(!line.empty()){
            cout<<justifyLine(line,L)<<endl;
        }
    }
}

int main(){
    string str = "GeeksforGeek is the best computer science portal for geeks.";
    int L = 16;

    justifyText(str, L);

    return 0;
}

