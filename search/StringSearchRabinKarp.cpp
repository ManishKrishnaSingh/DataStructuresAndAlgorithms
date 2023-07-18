#include <iostream>

using namespace std;

#define ALPHABET 256

const int PRIME = 101;

void rabinKarpSearch(string str, string pat)
{
    int M = str.length();
    int N = pat.length();

    int i, j, h = 1;
    for(i = 0; i < N-1; i++)
    {
        h = (ALPHABET * h) % PRIME;
    }

    int hashTxt = 0; //hash for str
    int hashPat = 0; //hash for pat
    for(i = 0; i < N; i++)
    {
        hashTxt = (ALPHABET * hashTxt + str[i]) % PRIME;
        hashPat = (ALPHABET * hashPat + pat[i]) % PRIME;
    }

    for(i = 0; i <= M-N; i++)
    {
        if(hashTxt == hashPat)
        {
            for(j = 0; j < N; j++)
            {
                if (str[i+j] != pat[j])
                {
                    break;
                }
            }

            if(j == N)
            {
                cout<<"Found at index "<<i<<"\n";
            }
        }

        if(i < M-N)
        {
            hashTxt = (ALPHABET * (hashTxt-str[i]*h) + str[i+N]) % PRIME;

            if(hashTxt < 0)
			{
                hashTxt = (hashTxt + PRIME);
            }
        }
    }
}

int main()
{
    string str = "ABACADAAADGACADAGJKACA";
    string pat = "ACADA";

    rabinKarpSearch(str, pat);

    return 0;
}

/************************
Time Complexity  : O(M*N)
Space Complexity : O(1)
*************************/
