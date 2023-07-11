#include <bits/stdc++.h>

using namespace std;

/***************************************************************
Given a binary string s, below two types of operations r allowed
Type-1:
	- remove the character at the start of the string s.
	- append it to the end of the string.
Type-2:
	- Pick any character in s and flip its value.
Return min type-2 operations to make s as alternating binary.
***************************************************************/

int minOf(int x,int y,int z){
    return min(x, min(y, z));
}

int minFlipsToAltBinStr(string iStr){
    if(iStr.empty()){
        return 0;
    }

    int w = iStr.length();
    int nflips = INT_MAX;

    iStr = iStr + iStr;
    int n = iStr.length();

    string altx="", alty="";
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            altx += "1";
            alty += "0";
        } else {
            altx += "0";
            alty += "1";
        }
    }

    int left,right;
    int diffx,diffy;
    left = right = 0;
    diffx = diffy = 0;
    //init window diffs
    while(right++ < w){
        if(iStr[right] != altx[right]){
            diffx += 1;
        }
        if(iStr[right] != alty[right]){
            diffy += 1;
        }
    }

    // update the initial difference
    nflips = minOf(nflips, diffx, diffy);

    //cont window diffs
    while(right < n){
        // add the difference of right
        if(iStr[right] != altx[right]){
            diffx += 1;
        }
        if(iStr[right] != alty[right]){
            diffy += 1;
        }

        // remove difference of left
        if(iStr[left] != altx[left]){
            diffx -= 1;
        }
        if(iStr[left] != alty[left]){
            diffy -= 1;
        }

        left++; right++; //increase indexes
        nflips = minOf(nflips, diffx, diffy);
    }

    return nflips;
}

int main() {
    cout<<"Minimum flips = "<<minFlipsToAltBinStr("010")<<endl;
    cout<<"Minimum flips = "<<minFlipsToAltBinStr("1110")<<endl;
    cout<<"Minimum flips = "<<minFlipsToAltBinStr("111000")<<endl;
    return 0;
}