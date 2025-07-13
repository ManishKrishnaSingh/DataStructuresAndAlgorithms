// https://leetcode.com/problems/meeting-rooms-iii/

#include <bits/stdc++.h>

using namespace std;

// {MeetingEndTime, RoomIndex}
typedef pair<int,int> EndTimeToRoom;
//using EndTimeToRoom = pair<int, int>;

int mostBooked(int rooms, vector<vector<int>>& meetings)
{
    // MinHeap {RoomIndex}
    priority_queue<int, vector<int>, greater<int>> available;

    // MinHeap {MeetingEndTime, RoomIndex}
    priority_queue<EndTimeToRoom, vector<EndTimeToRoom>, greater<EndTimeToRoom>> reserved;

    for (int i = 0; i < rooms; ++i)
    {
        available.push(i);
    }

    vector<int> roomBookingCount(rooms, 0);
    sort(meetings.begin(), meetings.end()); // Sort by StartTime

    int StartTime, EndTime, index;
    for (auto& meeting : meetings)
    {
        StartTime=meeting[0]; EndTime=meeting[1];

        // Free up meeting rooms that are no longer reserved by now
        while (!reserved.empty() && reserved.top().first <= StartTime)
        {
            available.push(reserved.top().second); reserved.pop();
        }

        if (!available.empty())
        {
            // Assign room with the smallest index.
            index = available.top(); available.pop();

            reserved.push({EndTime, index});
        }
        else
        {
            // Wait for the next meeting room to be available
            auto nextAvailable = reserved.top(); reserved.pop();

            index = nextAvailable.second;

            reserved.push({nextAvailable.first+(EndTime-StartTime), nextAvailable.second});
        }

        roomBookingCount[index]++;
    }

    int indexOfMostBookedRoom = 0;
    for (int i = 0; i < rooms; ++i)
    {
        if (roomBookingCount[indexOfMostBookedRoom] < roomBookingCount[i])
        {
            indexOfMostBookedRoom = i;
        }
    }

    return indexOfMostBookedRoom;
}

int main()
{
    int rooms1 = 2;
    vector<vector<int>> meetings1 = {{0,10},{1,5},{2,7},{3,4}};
    cout << "\nIndex of most booked room = " << mostBooked(rooms1, meetings1);

    int rooms2 = 3;
    vector<vector<int>> meetings2 = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    cout << "\nIndex of most booked room = " << mostBooked(rooms2, meetings2);

    return 0;
}
