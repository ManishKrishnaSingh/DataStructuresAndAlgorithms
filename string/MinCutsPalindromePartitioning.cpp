#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str, int low, int high){
    while(low<high){
        if(str[low]!=str[high]){
            return false;
        }
        low++; high--;
    }
    return true;
}

int minCutsPalindrome(string str, int low, int high){
    if(low>high || isPalindrome(str, low, high))
    {
        return 0;
    }

    int nCuts, minCuts=INT_MAX;
    for(int k=low; k<high; k++)
    {
        nCuts = 1 + minCutsPalindrome(str,low,k) + minCutsPalindrome(str,k+1,high);
        minCuts = min(minCuts, nCuts);
    }

    return minCuts;
}

int minimumCutsPalindrome(string str)
{
    int n = str.length();

    vector<int> dpMinimumCuts(n);
    vector<vector<bool>> IsPalindrome(n, vector<bool>(n, false));

    int i, j, currCuts;
    for (i=0; i<n; i++)
    {
        currCuts = i;
        for (j=0; j<=i; j++)
        {
            if (str[i] == str[j] && (i-j < 2 || IsPalindrome[j+1][i-1]))
            {
                IsPalindrome[j][i] = true;
                currCuts = min(currCuts, j==0 ? 0 : (1+dpMinimumCuts[j-1]));
            }
        }

        dpMinimumCuts[i] = currCuts;
    }

    return dpMinimumCuts[n-1];
}

int main() {
    string str = "ababbbabbababa";

    int nCuts = minCutsPalindrome(str, 0, str.length()-1);
    cout<<"\nMinimum Cuts[Palindrome Partitioning] = "<<nCuts;

    int minCuts = minimumCutsPalindrome(str);
    cout<<"\nMinimum Cuts[Palindrome Partitioning] = "<<minCuts;

    return 0;
}

/****************************
Using Recursion:
Time Complexity  : O(2^n)
Space Complexity : O(n)

Using Dynamic Programming:
Time Complexity  : O(n^2)
Space Complexity : O(n^2)
*****************************/
