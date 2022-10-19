#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int start, end;
}Interval;

bool compare(Interval& x, Interval& y){
    return (x.end < y.end);
}

vector<Interval> findDisjointIntervals(vector<Interval>& intervals){
    vector<Interval> djIntervals;

    if(intervals.size()){
        // sort list of interval by end time in asc order
        sort(intervals.begin(), intervals.end(), compare);

        djIntervals.push_back(intervals[0]);

        // end point of first interval
        int currEnd = intervals[0].end;
        for(int i=1; i<intervals.size(); i++){
            if (intervals[i].start > currEnd) {
                djIntervals.push_back(intervals[i]);
                currEnd = intervals[i].end;// update
            }
        }
    }

    return djIntervals;
}

int main(){
    vector<Interval> intervals = {
        {1,4}, {2,3}, {4,6}, {8,9}
    };

    auto djIntervals = findDisjointIntervals(intervals);

    // Print Disjoint Intervals
    for(auto djInterval : djIntervals){
        cout<<"{"<<djInterval.start<<","<<djInterval.end<<"}\n";
    }

    return 0;
}
