#include <iostream>

using namespace std;

//Longest Prefix Suffix
void lpsCompute(string iPattern, int n, int LPS[]){
    LPS[0] = 0;

    int i=1, len=0;
    while (i < n) {
        if (iPattern[i]==iPattern[len]) {
			LPS[i++] = ++len;
		} else {
			if (len!=0) {
				len = LPS[len-1];
			} else {
				LPS[i++] = 0;
			}
		}
	}
}

void kmpSearch(string iStr, string iPattern){
    int sLength = iStr.length();
    int pLength = iPattern.length();

    int LPS[pLength];
    lpsCompute(iPattern, pLength, LPS);

    int i=0, j=0;
    while (i<sLength) {
		if (iStr[i]==iPattern[j]) {
			i++; j++;
		}

		if (j==pLength) {
			cout<<"Found at index "<<(i-j)<<endl;
			j = LPS[j-1];
		} else if (i<sLength && iStr[i]!=iPattern[j]) {
			if (j!=0){
				j = LPS[j-1];
			} else {
				i = i+1;
			}
		}
    }
}

int main(){
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";

    kmpSearch(txt, pat);

    return 0;
}

