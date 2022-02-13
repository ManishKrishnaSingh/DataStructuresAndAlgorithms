#include <cmath>
#include <stack>
#include <iostream>

using namespace std;

typedef struct point {
    int x;
    int y;
}Point;

Point start;

int findOrientation(Point p, Point q, Point r){
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

int distance(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

Point secondTop(stack<Point>& stk){
    Point p = stk.top();
    stk.pop();
    Point res = stk.top();
    stk.push(p);
    return res;
}

int compare(const void *vp1, const void *vp2){
    Point *a = (Point *)vp1;
    Point *b = (Point *)vp2;

    int orientation = findOrientation(start, *a, *b);
    if (orientation == 0){
        return (distance(start, *b) >= distance(start, *a))? -1 : 1;
    }
    return (orientation == 2) ? -1 : 1;
}

stack<Point> GrahamScanConvexHull(Point points[], int n){
    stack<Point> stk;

    int min=0;//bottom-most
    for (int i=1; i<n; i++){
        if ((points[i].y<points[min].y) || (points[i].y==points[min].y && points[i].x < points[min].x)){
            min = i;
        }
    }

    swap(points[0], points[min]);
    start = points[0];//start-point
    qsort(&points[1], n-1, sizeof(Point), compare);

    int m = 1;
    for (int i=1; i<n; i++){
        while (i < n-1 && findOrientation(start, points[i],points[i+1]) == 0){
            i++;
        }
        points[m++] = points[i];
    }

    if (m >= 3){
        stk.push(points[0]);
        stk.push(points[1]);
        stk.push(points[2]);

        for (int i = 3; i < m; i++){
            while (stk.size()>1 && findOrientation(secondTop(stk), stk.top(), points[i]) != 2){
                stk.pop();
            }
            stk.push(points[i]);
        }
    }

    return stk;
}

int main(){
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);

    stack<Point> hull = GrahamScanConvexHull(points, n);

    while(!hull.empty()){
        Point top = hull.top();
        cout<<"{"<<top.x<<","<<top.y<<"}"<<endl;
        hull.pop();
    }

    return 0;
}

