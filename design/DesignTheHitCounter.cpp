#include <bits/stdc++.h>

using namespace std;

class HitCounter {
    queue<int> hits;

  public:
    HitCounter(){
    }

    void hit(int timestamp){
        hits.push(timestamp);
    }

    int getHits(int timestamp) {
        while (!hits.empty() && (timestamp - hits.front()) >= 300){
            hits.pop();
        }
        return hits.size();
    }
};

class HitCounterV2 {
    int currTotalHits;
    //Pair {timestamp, count}
    queue<pair<int,int>> hits;

  public:
    HitCounterV2(){
        currTotalHits = 0;
    }

    void hit(int timestamp) {
        if (hits.empty() || hits.back().first != timestamp) {
            hits.push({timestamp, 1});
        } else {
            hits.back().second++;
        }
        this->currTotalHits++;
    }

    int getHits(int timestamp){
        while (!hits.empty() && (timestamp - hits.front().first) >= 300) {
            this->currTotalHits -= hits.front().second; hits.pop();
        }
        return this->currTotalHits;
    }
};

int main(){
    cout<<"Hit Counter"<<endl;
    HitCounter hitCounter;

    hitCounter.hit(100);
    hitCounter.getHits(250);

    return 0;
}