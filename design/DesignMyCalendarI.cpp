#include <bits/stdc++.h>

using namespace std;

class MyCalendar {
    // map [end] = start
    map<int,int> mBooking;

  public:
    bool book(int start, int end)
    {
        bool result = false;
        auto itr = mBooking.upper_bound(start);
        if(itr==mBooking.end() || end <= itr->second)
        {
            result = true;
            mBooking[end]=start;
        }
        return result;
    }
};

int main(){
    MyCalendar objCalendar;

    cout<<boolalpha;
    cout<<"\nIs Booked ? "<<objCalendar.book(10, 20);
    cout<<"\nIs Booked ? "<<objCalendar.book(15, 25);
    cout<<"\nIs Booked ? "<<objCalendar.book(20, 30);

    return 0;
}