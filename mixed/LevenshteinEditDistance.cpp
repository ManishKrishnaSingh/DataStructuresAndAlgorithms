#include <vector>
#include <iostream>

using namespace std;

int minOf(int x, int y, int z){
    return min(x, min(y,z));
}

int findEditDistance(string str1, string str2, int n1, int n2){
    if(n1==0 || n2==0){
        return n1+n2;
    }
    if(str1[n1-1]==str2[n2-1]){
        return findEditDistance(str1, str2, n1-1, n2-1);
    }

    return 1 + minOf(
        findEditDistance(str1, str2, n1, n2-1),  //insert
        findEditDistance(str1, str2, n1-1, n2),  //remove
        findEditDistance(str1, str2, n1-1, n2-1) //replace
	);
}

int dpEditDistance(string str1, string str2){
    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];

    // base cases
    for(int i=0; i<=m; i++){
        dp[i][0] = i;
    }
    for(int j=0; j<=n; j++){
        dp[0][j] = j;
    }

    // populating matrix
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
	    } else {
                dp[i][j] = 1 + minOf(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
	    }
        }
    }
    return dp[m][n];
}

int main(){
    string str1 = "sunday";
    string str2 = "monday";

    int n1 = str1.length();
    int n2 = str2.length();

    int distance = findEditDistance(str1,str2,n1,n2);
    cout<<"Lavenstine distance = "<<distance<<endl;

    int editdistance = dpEditDistance(str1,str2);
    cout<<"Lavenstine distance = "<<editdistance<<endl;

    return 0;
}
