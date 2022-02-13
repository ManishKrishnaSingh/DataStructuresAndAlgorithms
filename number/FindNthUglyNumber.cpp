#include <iostream>

using namespace std;

int minOf(int x, int y, int z){
    return min(x, min(y,z));
}

int findNthUglyNumber(int n){
    int dp[n];

    int i2=0, i3=0, i5=0;
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;

    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = minOf(nextMultipleOf2,nextMultipleOf3,nextMultipleOf5);
        if(dp[i] == nextMultipleOf2){
            nextMultipleOf2 = dp[++i2]*2;
        }
        if(dp[i] == nextMultipleOf3){
            nextMultipleOf3 = dp[++i3]*3;
        }
        if(dp[i] == nextMultipleOf5){
            nextMultipleOf5 = dp[++i5]*5;
        }
    }
    return dp[n-1];
}

int main() {
    int n = 150;

    int nthUglyNum = findNthUglyNumber(n);
    cout<<"Ugly Number="<<nthUglyNum<<endl;

    return 0;
}

