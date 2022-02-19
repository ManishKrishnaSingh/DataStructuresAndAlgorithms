#include <bits/stdc++.h>

using namespace std;

int minInsertions(string str, int low, int high){
    if(low > high){
        return -1;
    }
    if(low == high){
        return 0;
    }

    if(low+1 == high){
        if(str[low] == str[high]) {
            return 0;
        } else {
            return 1;
        }
    }

    if(str[low] == str[high]){
        return minInsertions(str, low+1, high-1);
    } else {
        return min(minInsertions(str, low, high-1), minInsertions(str, low+1, high)) + 1;
    }
}

int findMinInsertions(string str){
    int low = 0, high = str.length() - 1;
    return minInsertions(str, low, high);
}

int dpMinInsertions(string str){
    int n = str.length();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int window=1; window<n; window++){
        for(int low=0,high=window; high<n; low++,high++){
            if(str[low] ==  str[high]){
                dp[low][high] = dp[low+1][high-1];
            } else {
                dp[low][high] = 1 + min(dp[low][high-1], dp[low+1][high]);
            }
        }
    }

    return dp[0][n-1];
}

int main(){
    int nInsertions = findMinInsertions("google");
    cout<<"Min Insertions = "<<nInsertions<<endl;

    int noInsertions = dpMinInsertions("google");
    cout<<"Min Insertions = "<<noInsertions<<endl;

    return 0;
}

