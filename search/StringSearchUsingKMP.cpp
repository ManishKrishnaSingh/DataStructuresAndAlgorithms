#include <bits/stdc++.h>

using namespace std;

// Longest Prefix Suffix
void LpsCompute(string& pat, vector<int>& LPS)
{
    int index  = 1;
    int length = 0;
    int n = LPS.size();

    LPS[0] = 0;
    while(index < n)
    {
        if (pat[index] == pat[length])
        {
            LPS[index++] = ++length;
        }
        else
        {
            if (length == 0)
            {
				LPS[index++] = 0;
            }
            else
            {
                length = LPS[length-1];
            }
        }
    }
}

void kmpSearch(string& str, string& pat)
{
    int M = str.length();
    int N = pat.length();

    vector<int> LPS(N);
    LpsCompute(pat, LPS);

    int i=0, j=0;
    while(i < M)
    {
        if(str[i] == pat[j])
        {
            i++; j++;
        }

        if(j == N)
        {
			cout<<"Found at index "<<(i-j)<<"\n";
			j = LPS[j-1];
        }
        else if (i < M && str[i] != pat[j])
        {
            if (j != 0)
            {
				j = LPS[j-1];
            }
            else
            {
				i++;
            }
        }
    }
}

int main()
{
    string str = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";

    kmpSearch(str, pat);

    return 0;
}

/************************
Time Complexity  : O(M*N)
Space Complexity : O(N)
*************************/