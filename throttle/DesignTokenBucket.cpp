#include <bits/stdc++.h>

using namespace std;

class TokenBucket
{
    mutex mtx;

    int rate;
    int maxTokens;
    int available;

    using clock = std::chrono::steady_clock;
    clock::time_point lastRefill{clock::now()};

  public:
    TokenBucket(int rate, int maxTokens): rate(rate), maxTokens(maxTokens), available(0)
    {
        // Constructor
    }

    bool requestToken(int nTokens)
    {
        lock_guard<mutex> lock(mtx);
        RefillTokens(); // Refill
        return IsPossible(nTokens);
    }

  private:
    void RefillTokens()
    {
        auto now = clock::now();
        auto duration = chrono::duration_cast<chrono::seconds>(now - lastRefill);

        available += rate * duration.count();
        available = min(available, maxTokens);
        lastRefill = now; // update last refill
    }

    bool IsPossible(int requested)
    {
        if (requested <= available)
        {
            available -= requested;
            return true;
        }
        return false;
    }
};

int main()
{
    TokenBucket bucket(1, 20);

    this_thread::sleep_for(chrono::seconds(5));
    cout<<boolalpha<<bucket.requestToken(3)<<endl;

    this_thread::sleep_for(chrono::seconds(6));
    cout<<boolalpha<<bucket.requestToken(8)<<endl;

    this_thread::sleep_for(chrono::seconds(4));
    cout<<boolalpha<<bucket.requestToken(6)<<endl;

    return 0;
}
