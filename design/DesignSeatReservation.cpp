#include <bits/stdc++.h>

using namespace std;

class SeatReservationManager
{
    int maxSeatNumber;
    priority_queue<int,vector<int>,greater<int>> minHeap;

  public:
    SeatReservationManager(int nSeats)
    {
        this->maxSeatNumber = nSeats;
        for(int i=1; i <= nSeats; i++)
        {
            minHeap.push(i);
        }
    }

    int reserve()
    {
        int top = minHeap.top(); minHeap.pop();
        return top;
    }

    void unreserve(int seatNumber)
    {
        if(seatNumber<=maxSeatNumber)
        {
            minHeap.push(seatNumber);
        }
    }
};

int main()
{
    cout<<"Seat Reservation Manager"<<endl;
    return 0;
}