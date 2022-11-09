#include <bits/stdc++.h>

using namespace std;

class AuthenticationManager
{
    int timeToLive;
    unordered_map<string,int> mTokenToTime;

  public:
    AuthenticationManager(int iTimeToLive)
    {
        timeToLive = iTimeToLive;
    }

    void generate(string iTokenId, int iCurrTime)
    {
        if(mTokenToTime.count(iTokenId) == 0)
        {
            mTokenToTime.insert({iTokenId, iCurrTime});
        }
    }

    void renew(string iTokenId, int iCurrTime)
    {
        if(mTokenToTime.count(iTokenId))
        {
            // renew only if the token is still unexpired/valid
            if(timeToLive + mTokenToTime[iTokenId] > iCurrTime)
            {
                mTokenToTime[iTokenId] = iCurrTime;
            }
        }
    }

    int countUnexpiredTokens(int iCurrTime)
    {
        int unexpiredTokens = 0;
        for(auto entry : mTokenToTime)
        {
            if((timeToLive + entry.second) > iCurrTime)
            {
                unexpiredTokens++;
            }
        }
        return unexpiredTokens;
    }
};

int main()
{
    std::cout << "Authentication Manager\n";
    AuthenticationManager appAuthManager(10);

    return 0;
}