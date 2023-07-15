#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef pair<int,int> Point;

int findGCD(int a, int b){
    if (a==0 || b==0){
        return a+b;
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

string findSlope(Point a, Point b){
    int x = a.first  - b.first;
    int y = a.second - b.second;
    int gcd = findGCD(x, y);
    //reduce diff by their gcd
    x = x/gcd; y = y/gcd;
    return x + "-" + y;
}

int maxPointOnSameLine(vector<Point> points, int n){
    if (n < 2){
        return n;
    }

    int nPoints, maxPoint = 0;
    unordered_map<string, int> mSlope;
    for (int i=0; i<n-1; i++){
        nPoints = 0;
        for (int j=i+1; j<n; j++){
            string slope = findSlope(points[i], points[j]);
            mSlope[slope]++;
            nPoints = max(nPoints, mSlope[slope]);
        }
        maxPoint = max(maxPoint, nPoints);
        mSlope.clear();
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

