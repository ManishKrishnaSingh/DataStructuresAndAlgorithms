#include <vector>
#include <iostream>

using namespace std;

typedef struct point {
    int x;
    int y;
}Point;

int orientation(Point p, Point q, Point r){
    int num = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    //clockwise
    if(num > 0) {
        return 1;
    }
    //anti-clockwise
    if(num < 0){
        return 2;
    }
    //collinear
    return 0;
}

vector<Point> JarvisMarchConvexHull(Point points[], int n){
    vector<Point> result;
    if(n >= 3){
        int start=0;//left-most
        for(int i=1; i<n; i++){
            if(points[i].x < points[start].x){
                start = i;
            }
        }

        int curr = start;
        do {
            result.push_back(points[curr]);

            int next = (curr+1)%n;
            for(int i=0; i<n; i++){
                if(orientation(points[curr], points[i], points[next]) == 2){
                    next=i;
                }
            }
            curr=next;
        } while(curr!=start);
    }
    return result;
}

int main(){
    Point points[] = {{0,3},{2,2},{1,1},{2,1},{3,0},{0,0},{3,3}};
    int n = sizeof(points)/sizeof(points[0]);

    vector<Point> hull = JarvisMarchConvexHull(points, n);
    for(int i=0; i<hull.size(); i++){
        cout<<"{"<<hull[i].x<<","<<hull[i].y<<"}"<<endl;
    }

    return 0;
}

