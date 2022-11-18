#include <bits/stdc++.h>

using namespace std;

class MyCalendarThree
{
    map<int,int> mTimes;

  public:
    bool book(int begTime, int endTime)
    {
        bool result = true;

        // insert booking
        mTimes[begTime]++; 
        mTimes[endTime]--; 

        int bookingCount = 0;
        for (auto entry : mTimes)
        {
            bookingCount += entry.second;
            if(bookingCount > 2)
            {
                break;
            }
        }

        // remove booking
        if(bookingCount > 2)
        {
            result = false;
            mTimes[begTime]--; 
            mTimes[endTime]++;
        }

        return result;
    }
};

int main()
{
    cout<<"MyCalendar - II\n";

    MyCalendarThree objCalendar;
    
    cout<<boolalpha;
    cout<<"\nIs Triple Booking ? "<<objCalendar.book(10, 20); // true
    cout<<"\nIs Triple Booking ? "<<objCalendar.book(50, 60); // true
    cout<<"\nIs Triple Booking ? "<<objCalendar.book(10, 40); // true
    cout<<"\nIs Triple Booking ? "<<objCalendar.book(5, 15);  // false
    cout<<"\nIs Triple Booking ? "<<objCalendar.book(5, 10);  // true
    cout<<"\nIs Triple Booking ? "<<objCalendar.book(25, 55); // true

    return 0;
}