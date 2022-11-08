#include <bits/stdc++.h>

using namespace std;

class LoggerRateLimiter
{
    unordered_map<string,int> mLogTime;

  public:
    LoggerRateLimiter()
    {
        //TODO:
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        if (mLogTime.find(message) == mLogTime.end())
        {
            mLogTime[message] = timestamp;
            return true;
        }

        int prevTimestamp = mLogTime[message];
        if (timestamp - prevTimestamp >= 10)
        {
            mLogTime[message] = timestamp;
            return true;
        }

        return false;
    }
};

int main()
{
    LoggerRateLimiter logger;

    cout<<boolalpha<<endl;
    cout<<logger.shouldPrintMessage(1, "foo")<<endl;
    cout<<logger.shouldPrintMessage(2, "bar")<<endl;
    cout<<logger.shouldPrintMessage(3, "foo")<<endl;
    cout<<logger.shouldPrintMessage(8, "bar")<<endl;
    cout<<logger.shouldPrintMessage(10,"foo")<<endl;
    cout<<logger.shouldPrintMessage(11,"foo")<<endl;

    return 0;
}