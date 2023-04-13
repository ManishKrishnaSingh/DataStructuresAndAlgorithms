#include <bits/stdc++.h>

using namespace std;

typedef struct packet
{
    int id, size;
    packet(int id, int size): id(id), size(size){}
} Packet;

class LeakyBucket
{
    queue<Packet> qBucket;
    int leakRate, currSize, maxSize;

    public:
    LeakyBucket(int iRate, int iSize): leakRate(iRate), currSize(0), maxSize(iSize){}

    void addPacket(Packet iPacket)
    {
        if(currSize+iPacket.size > maxSize)
        {
            cout << "Packet has been Discarded.\n"; return ;
        }

        //add to bucket queue
        qBucket.push(iPacket);
        currSize += iPacket.size;
        cout << "Packet [" << iPacket.id <<  "] added.\n";
    }

    void TransmitPacket()
    {
        if(qBucket.empty())
        {
            cout << "No packets in the bucket.\n"; return ;
        }

        //init current leak size
        int leakSize = leakRate;
        while(!qBucket.empty())
        {
            Packet front = qBucket.front();

            if(front.size > leakSize)
            {
                break; //Not transmitted
            }
            qBucket.pop(); //remove
            leakSize -= front.size;
            currSize -= front.size;

            cout << "Packet [" << front.id << "] transmitted.\n";
        }
    }
};

int main()
{
    LeakyBucket bucket(25, 100);

    bucket.addPacket(Packet(1, 12));
    bucket.addPacket(Packet(2, 10));
    bucket.addPacket(Packet(3, 10));
    bucket.addPacket(Packet(4, 10));
    bucket.addPacket(Packet(5, 15));
    bucket.addPacket(Packet(6, 25));

    while(true)
    {
        // Called on Clock Tick
        bucket.TransmitPacket();

        cout << "Waiting for next tick..\n";
        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    return 0;
}
