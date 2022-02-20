// ----------------------------------------------------------
// Cn = C0*Cn-1 + C1*Cn-2+ + C3*Cn-3 +....+ Cn-2*C1 + Cn-1*C0
// ----------------------------------------------------------

#include <iostream>

using namespace std;

int catalan(int n){
    if (n <= 1){
        return 1;
    }

    int answer = 0;
    for (int i=0; i<n; i++){
        answer += catalan(i)*catalan(n-i-1);
    }
    return answer;
}

int PrintCatalan(int n){
    int dp[n+1];
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i] = 0;
        for(int j=0; j<i; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    cout<<"Catalan Numbers:";
    for(int i=0; i<10; i++){
        cout<<" "<<catalan(i);
    }

    cout<<endl<<endl;

    cout<<"Catalan Numbers:";
    for(int i=0; i<10; i++){
        cout<<" "<<PrintCatalan(i);
    }

    return 0;
}

