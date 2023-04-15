//Refs: https://www.enjoyalgorithms.com/blog/design-api-rate-limiter
#include <bits/stdc++.h>

using namespace std;

class SlidingWindowRateLimiter
{
    int timeWindow;
    int maxRequests;
    queue<int> qRequests;

  public:
    SlidingWindowRateLimiter(int iTimeWindow, int iMaxRequests): timeWindow(iTimeWindow), maxRequests(iMaxRequests)
    {
        // Constructor
    }

    bool IsRequestAllowed(int iTimestamp)
    {
        int diff = iTimestamp - this->timeWindow;
        if(diff > 0)
        {
            while (!this->qRequests.empty() and this->qRequests.front() <= diff )
            { 
                this->qRequests.pop();// pop front if ts is older than allowed ts
            }
        }

        if(this->qRequests.size() < this->maxRequests)
        {
            this->qRequests.push(iTimestamp); return true;
        }

        return false;
    }
};

int main()
{
    cout<<"Sliding Window Rate Limiter:-"<<endl;
    SlidingWindowRateLimiter swRateLimiter(5, 5);

    cout<<boolalpha<<endl;
    cout<<swRateLimiter.IsRequestAllowed(1)<<endl;
    cout<<swRateLimiter.IsRequestAllowed(2)<<endl;
    cout<<swRateLimiter.IsRequestAllowed(2)<<endl;
    cout<<swRateLimiter.IsRequestAllowed(3)<<endl;
    cout<<swRateLimiter.IsRequestAllowed(3)<<endl;
    cout<<swRateLimiter.IsRequestAllowed(3)<<endl;
    cout<<swRateLimiter.IsRequestAllowed(5)<<endl;
    cout<<swRateLimiter.IsRequestAllowed(8)<<endl;

    return 0;
}