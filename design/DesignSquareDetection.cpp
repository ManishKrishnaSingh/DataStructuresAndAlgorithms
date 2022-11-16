#include <bits/stdc++.h>

using namespace std;

class DetectSquares
{
    // hash map {X, hash map {Y, count} || mCount[X][Y]
    unordered_map<int, unordered_map<int, int>> mCount;

  public:
    DetectSquares()
    {
        mCount.clear();
    }

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        if (mCount.find(x) == mCount.end())
        {
            mCount[x] = {};
        }
        mCount[x][y] = mCount[x][y] + 1;
    }

    int count(vector<int> point)
    {
        int squareCount = 0;
        int x1, y1, x2, y2, diff;

        x1=point[0]; y1=point[1];
        for (auto &entry: mCount[x1])
        {
            //skip same point
            y2 = entry.first;
            if (y2 == y1)
            {
                continue;
            }
            diff = abs(y2 - y1);

            // x1-diff
            x2 = x1-diff;
            if (x2 >= 0)
            {
                squareCount += (mCount[x1][y2] * mCount[x2][y2] * mCount[x2][y1]);
            }

            // x1+diff
            x2 = x1+diff;
            if (x2 < 1001)
            {
                squareCount += (mCount[x1][y2] * mCount[x2][y2] * mCount[x2][y1]);
            }
        }

        return squareCount;
    }
};

int main()
{
    cout<<"Detect Squares"<<endl;
    DetectSquares detectSquares;

    detectSquares.add({3, 10});
    detectSquares.add({11, 2});
    detectSquares.add({3,  2});
    cout<<"\nSquare Count="<<detectSquares.count({11,10});
    cout<<"\nSquare Count="<<detectSquares.count({14, 8});

    detectSquares.add({11, 2});
    cout<<"\nSquare Count="<<detectSquares.count({11, 10});

    return 0;
}