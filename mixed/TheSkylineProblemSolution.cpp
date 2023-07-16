#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Strip;

vector<Strip> findSkyLine(int buildings[][3], int N)
{
    vector<Strip> wall;

    int i,left,height,right;
    for(i = 0; i < N; i++)
    {
        left   = buildings[i][0];
        right  = buildings[i][1];
        height = buildings[i][2];

        wall.push_back(make_pair(left, -height));
        wall.push_back(make_pair(right, height));
    }

    // sort the wall list
    sort(wall.begin(), wall.end());

    vector<Strip> skyLine;

    int top = 0;
    multiset<int> leftWallHeight = {0};
    for(auto& w : wall)
    {
        if (w.second < 0)
        {
            leftWallHeight.insert(abs(-w.second));
        }
        else
        {
            leftWallHeight.erase(leftWallHeight.find(w.second));
        }

        if (*leftWallHeight.rbegin() != top)
        {
            top = *leftWallHeight.rbegin();
            skyLine.push_back(make_pair(w.first, top));
        }
    }

    return skyLine;
}

int main()
{
    int buildings[][3]=
    {
        {1,   5, 11},
        {2,   7,  6},
        {3,   9, 13},
        {12, 16,  7},
        {14, 25,  3},
        {19, 22, 18},
        {23, 29, 13},
        {24, 28,  4}
    };
    int n = sizeof( buildings)/sizeof( buildings[0]);

    vector<Strip> skyLine = findSkyLine(buildings, n);

    cout<<"SkyLine => ";
    for(auto& strip : skyLine)
    {
        cout<<"{"<<strip.first<<","<<strip.second<<"} ";
    }

    return 0;
}

