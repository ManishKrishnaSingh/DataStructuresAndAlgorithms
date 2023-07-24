#include <bits/stdc++.h>

using namespace std;

/******************************************************************************
Given N and K, Construct a palindrome of size N using a binary number of size K
repeating itself to wrap into the palindrome. The palindrome shall always begin
with 1 and contains maximum number of 0's.
*******************************************************************************/

void dfs(vector<vector<int>>& graph, int u, vector<int>& answer)
{
    answer[u] = 1;

    for(auto& v : graph[u])
    {
        if(answer[v] == 0)
        {
            dfs(graph, v, answer);
        }
    }
}

void BinaryPalindrome(int N, int K)
{
    vector<int> answer(N, 0);
    vector<int> arrOfIndex(N);

    // graph of connected chars
    vector<vector<int>> graph(K);

    for(int i = 0; i < N; i++)
    {
        arrOfIndex[i] = i%K;
    }

    int i, lftIndex, rhtIndex;
    for(i = 0; i < (N/2); i++)
    {
        lftIndex = arrOfIndex[i];
        rhtIndex = arrOfIndex[N-i-1];

        // connect chars as in palindrome
        graph[lftIndex].push_back(rhtIndex);
        graph[rhtIndex].push_back(lftIndex);
    }

    dfs(graph, 0, answer); // set all connected to 1st char as 1

    // Print Binary Palindrome
    for(auto& index : arrOfIndex)
    {
        cout<<answer[index]<<" ";
    }
}

int main()
{
    int N = 10, K = 4;

    BinaryPalindrome(N,K);

    return 0;
}

/**********************
Time Complexity  : O(N)
Space Complexity : O(N)
***********************/
