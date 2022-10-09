#include <bits/stdc++.h>

using namespace std;

unordered_set<string> dictionary = {
    "apple", "orange", "i", "icecream", "and", "like", "yellow"
};

bool IsBreakable(string iStr){
    if(iStr.empty()){
        return true;
    }

    int n = iStr.size();

    bool dp[n + 1];
    memset(dp, false, sizeof(dp));

    for (int i=1; i<=n; i++){
        if (!dp[i] && dictionary.find(iStr.substr(0,i)) != dictionary.end()){
            dp[i] = true;

            // last char
            if (i == n){
                return true;
            }
        }

        if (dp[i] == true){
            for (int j=i+1; j<=n; j++){
                if (!dp[j] && dictionary.find(iStr.substr(i, j-i) ) != dictionary.end()){
                    dp[j] = true;

                    // last char
                    if (j == n){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main(){
    cout<<boolalpha<<IsBreakable("ilikeappleandorange")<<endl;
    cout<<boolalpha<<IsBreakable("ilikeyellowicecream")<<endl;

    return 0;
}
