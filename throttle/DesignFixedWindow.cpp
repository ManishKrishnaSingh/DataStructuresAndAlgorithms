//Refs: https://www.enjoyalgorithms.com/blog/design-api-rate-limiter
#include <bits/stdc++.h>

using namespace std;

class FixedWindowRateLimiter
{
    int curRequests;
    int maxRequests;
    int winTimestamp;

  public:
    FixedWindowRateLimiter(int iMaxRequests): curRequests(0), maxRequests(iMaxRequests), winTimestamp(0)
    {
        // Constructor
    }

    bool IsRequestAllowed(int iTimestamp)
    {
        if(iTimestamp >= this->winTimestamp)
        {
            if(iTimestamp != this->winTimestamp)
            {
                this->curRequests  = 1;
                this->winTimestamp = iTimestamp;
                return true; // reset the counter
            }
            else if(this->curRequests < this->maxRequests)
            {
                this->curRequests++; return true;
            }
        }

        return false;
    }
};

int main()
{
    cout<<"Fixed Window Rate Limiter:-"<<endl;
    FixedWindowRateLimiter fwRateLimiter(4);

    cout<<boolalpha<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(1)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(2)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(2)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(2)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(2)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(2)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(3)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(5)<<endl;
    cout<<fwRateLimiter.IsRequestAllowed(5)<<endl;

    return 0;
}