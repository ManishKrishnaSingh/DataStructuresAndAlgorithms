#include <iostream>

using namespace std;

#define d 256 //no of chars in input alphabet

const int prime = 101; //prime number

void rabinKarpSearch(string pat, string txt){
    int m = pat.length();
    int n = txt.length();

    int h=1;
    for(int i=0; i<m-1; i++){
        h = (d*h) % prime;
    }

    int hashTxt = 0; //hash for txt
    int hashPat = 0; //hash for pat
    for(int i=0; i<m; i++){
        hashPat = (d*hashPat + pat[i]) % prime;
        hashTxt = (d*hashTxt + txt[i]) % prime;
    }

    for(int i=0; i<=n-m; i++){
        if(hashTxt==hashPat){
            int j;
            for(j=0; j<m; j++){
                if (txt[i+j] != pat[j]){
                    break;
                }
            }
            if(j==m){
                cout<<"Found at index "<<i<<endl;
            }
        }

        if(i < n-m){
            hashTxt = (d*(hashTxt-txt[i]*h) + txt[i+m])%prime;
            if(hashTxt < 0){
                hashTxt = (hashTxt + prime);
            }
        }
    }
}

int main(){
    string txt = "ABACADAAADGACADAGJKACA";
    string pat = "ACADA";

    rabinKarpSearch(pat, txt);

    return 0;
}

