#include <bits/stdc++.h>

using namespace std;

class MyCalendarThree
{
    map<int,int> mTimes;

  public:
    int book(int begTime, int endTime)
    {
        mTimes[begTime]++; 
        mTimes[endTime]--; 

        int curEvents=0, maxEvents=0;
        for (auto entry : mTimes)
        {
            curEvents = curEvents + entry.second;
            maxEvents = max(maxEvents, curEvents);
        }

        return maxEvents;
    }
};

int main()
{
    cout<<"MyCalendar - III\n";

    MyCalendarThree objCalendar;

    cout<<"\nNo of Events = "<<objCalendar.book(10, 20); // 1
    cout<<"\nNo of Events = "<<objCalendar.book(50, 60); // 1
    cout<<"\nNo of Events = "<<objCalendar.book(10, 40); // 2
    cout<<"\nNo of Events = "<<objCalendar.book(5, 15);  // 3
    cout<<"\nNo of Events = "<<objCalendar.book(5, 10);  // 3
    cout<<"\nNo of Events = "<<objCalendar.book(25, 55); // 3

    return 0;
}