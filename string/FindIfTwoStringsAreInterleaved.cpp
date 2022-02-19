#include <cstring>
#include <iostream>

using namespace std;

bool isInterleaved(string aStr, string bStr, string fStr){
	if(aStr.empty() && bStr.empty() && fStr.empty()){
		return true;
	}

	if(fStr.empty()){
		return false;
	}

	int a = aStr.length();
	int b = bStr.length();
	int f = fStr.length();

	if((a+b) != f){
	   return false;
	}

	bool a2f = false;
	bool b2f = false;

	if(a>0 && aStr[0] == fStr[0]){
	    a2f = isInterleaved(aStr.substr(1,a-1),bStr,fStr.substr(1,f-1));
	}

	if(b>0 && bStr[0] == fStr[0]){
	    b2f = isInterleaved(aStr,bStr.substr(1,b-1),fStr.substr(1,f-1));
	}

	return a2f || b2f;
}

bool findIfInterleaved(string aStr, string bStr, string fStr){
    int a = aStr.length();
    int b = bStr.length();
    int f = fStr.length();

    bool dp[a+1][b+1];
    memset(dp, false, sizeof(dp));

    if((a+b) != f){
        return false;
    }

    for(int i=0; i<=a; i++) {
	    for(int j=0; j<=b; j++) {
	        if (i==0 && j==0){
	            dp[i][j] = true;
	        } else if (i==0 && bStr[j-1]==fStr[j-1]) {
	            dp[i][j] = dp[i][j-1];
	        } else if (j==0 && aStr[i-1]==fStr[i-1]) {
	            dp[i][j] = dp[i-1][j];
	        } else if (aStr[i-1]==fStr[i+j-1] && bStr[j-1]!= fStr[i+j-1]){
	            dp[i][j] = dp[i-1][j];
	        } else if (aStr[i-1]!=fStr[i+j-1] && bStr[j-1]==fStr[i+j-1]){
	            dp[i][j] = dp[i][j-1];
	        } else if (aStr[i-1]==fStr[i+j-1] && bStr[j-1]==fStr[i+j-1]){
	            dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
	        }
	    }
    }

    return dp[a][b];
}

int main(){
    string aStr = "XXY";
    string bStr = "XXZ";
    string fStr = "XXZXXY";

    bool res = isInterleaved(aStr, bStr, fStr);
    cout<<"Is isInterleaved = "<<res<<endl;

    bool result = findIfInterleaved(aStr, bStr, fStr);
    cout<<"Is isInterleaved = "<<result<<endl;

	return 0;
}

