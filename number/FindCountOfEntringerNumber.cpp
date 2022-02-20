// The Entringer Number E(n, k) are the number of permutations of {1, 2, …, n + 1}, starting with k + 1, which, after initially falling, alternatively fall then rise.
// E(N,K) = E(N,K-1) + E(N-1,N-K)

/*
Example,
E(4,2)=4

They are:
3 2 4 1 5
3 2 5 1 4
3 1 4 2 5
3 1 5 2 4
*/

#include <cstring>
#include <iostream>

using namespace std;

int ZigZag(int n, int k){
    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));

    //initialize
    dp[0][0] = 1;
    for (int i=1; i<=n; i++){
        dp[i][0] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][i-j];
        }
    }
    return dp[n][k];
}

int main(){
    int N=4, K=3;

    int number = ZigZag(N,K);
    cout<<"Entringer Number = "<<number<<endl;

    return 0;
}

