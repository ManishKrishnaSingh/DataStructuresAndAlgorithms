#include <vector>
#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;

typedef pair<int,int> Point;

class PointHash{
    public:
    std::size_t operator() (const Point& point) const {
        return std::hash<int>()(point.first) ^ std::hash<int>()(point.second);
    }
};

int findGCD(int a, int b){
    if (a == 0){
        return b;
    } else if (b == 0){
        return a;
    } else if(a<0 && b<0){
        return findGCD(abs(a), abs(b));
    } else if((a<0 && b>0) || (a>0 && b<0)){
        return -1*findGCD(abs(a), abs(b));
    }

    if (a == b){
        return a;
    } else if (a > b){
        return findGCD(a-b, b);
    } else {
        return findGCD(a, b-a);
    }
}

int maxPointOnSameLine(vector<Point> points, int n){
    if (n < 2){
        return n;
    }

    int nPoints, maxPoint = 0;
    int overlapPoints, verticalPoints;
    unordered_map<Point, int, PointHash> slopeMap;

    for (int i=0; i<n; i++){
        nPoints = 0;
        overlapPoints = 0;
        verticalPoints = 0;

        for (int j=i+1; j<n; j++){
            if (points[i] == points[j]){
                overlapPoints++;
            } else if (points[i].first == points[j].first){
                verticalPoints++;
            } else {
                int xDiff = points[j].first  - points[i].first;
                int yDiff = points[j].second - points[i].second;

                int gcd = findGCD(xDiff, yDiff);
                //reduce diff by their gcd
                xDiff /= gcd; yDiff /= gcd;

                slopeMap[make_pair(yDiff, xDiff)]++;
                nPoints = max(nPoints, slopeMap[make_pair(yDiff, xDiff)]);
            }
            nPoints = max(nPoints, verticalPoints);
        }

        maxPoint = max(maxPoint, nPoints+overlapPoints+1);
        slopeMap.clear();
    }
    return maxPoint;
}

int main(){
    vector<Point> points = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4}};
    int n = points.size();

    int maxPoints = maxPointOnSameLine(points, n);
    cout<<"Maximum Points on Same Line = "<<maxPoints<<endl;

    return 0;
}

