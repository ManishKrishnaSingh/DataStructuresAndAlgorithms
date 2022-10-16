#include <bits/stdc++.h>

using namespace std;

int minEatingSpeed(vector<int>& piles, int maxHours){
    if(!piles.size()){
        return -1;
    }

    int curHours;
    int minSpeed = INT_MAX;
    int low=1, mid, high=*max_element(piles.begin(), piles.end());

    while(low <= high){
        curHours = 0;
        mid = (low+high) >> 1;

        // calculate current eating hours 
        for(int i=0; i<piles.size(); i++){
            curHours += ceil((double)piles[i]/mid);
        }

        // update low / high
        if(curHours > maxHours){
            low = mid + 1;
        } else {
            high = mid - 1;
            //update minimum eating speed
            minSpeed = min(mid, minSpeed);
        }
    }

    return minHours;
}

int main(){
    int maxHours = 6;
    vector<int> piles = {
        30, 11, 23, 4, 20
    };

    cout<<minEatingSpeed(piles, maxHours);

    return 0;
}