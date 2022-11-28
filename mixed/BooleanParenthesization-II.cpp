#include <bits/stdc++.h>

using namespace std;

int dp[10][10][2];

int countWays(string str, int i, int j, int isTrue){
    if(i > j){
        return 0;
    }

    if(i == j){
        if(isTrue){
            return str[i] == 'T';
        } else {
            return str[i] == 'F';
        }
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    int counter = 0;
    for(int k=i+1; k<=j-1; k=k+2){
        int leftT,leftF,rightT,rightF;

        if(dp[i][k-1][1] == -1){
            leftT = countWays(str,i,k-1,1);
        } else {
            leftT = dp[i][k-1][1];
        }

        if(dp[i][k-1][0] == -1){
            leftF = countWays(str,i,k-1,0);
        } else {
            leftF = dp[i][k-1][0];
        }

        if(dp[k+1][j][1] == -1){
            rightT = countWays(str,k+1,j,1);
        } else {
            rightT = dp[k+1][j][1];
        }

        if(dp[k+1][j][0] == -1){
            rightF = countWays(str,k+1,j,0);
        } else {
            rightF = dp[k+1][j][0];
        }

        if(str[k] == '^'){
            if(isTrue){
                counter += (leftT*rightF) + (leftF*rightT);
            } else {
                counter += (leftT*rightT) + (leftF*rightF);
            }
        } else if(str[k] == '&'){
            if(isTrue){
                counter += (leftT*rightT);
            } else {
                counter += (leftT*rightF) + (leftF*rightT) + (leftF*rightF);
            }
        } else if(str[k] == '|'){
            if(isTrue){
                counter += (leftT*rightF) + (leftF*rightT) + (leftT*rightT);
            } else {
                counter += (leftF*rightF);
            }
        }

        dp[i][j][isTrue] = counter%1003;
    }
    return counter%1003;
}

int numOfWays(string symbols, string operators){
    string str;
    int i, j=0;
    for(i=0; i<symbols.length(); i++){
        str.push_back(symbols[i]);
        if(j < operators.length()){
            str.push_back(operators[j++]);
        }
    }
    int n = str.length();

    memset(dp,-1,sizeof(dp));
    return countWays(str,0,n-1,1);
}

int main() {
    string symbols = "TTFT";
    string operators = "|&^";

    int nWays=numOfWays(symbols,operators);
    cout<<"Number Of Ways = "<<nWays<<endl;

    return 0;
}

