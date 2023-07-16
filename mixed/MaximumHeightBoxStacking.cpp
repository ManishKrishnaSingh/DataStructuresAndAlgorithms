#include <bits/stdc++.h>

using namespace std;

int dp[100];

typedef struct box
{
    int length, width, height;
}Box;

bool compare(Box b1, Box b2)
{
    return (b1.length*b1.width) < (b2.length*b2.width);
}

int findMaxHeight(vector<Box>& boxes, int bIndex, int index)
{
    if(index < 0)
    {
        return 0;
    }

    if(dp[index] != -1)
    {
        return dp[index];
    }

    int maximumHeight = 0;
    for(int i=index; i>=0; i--)
    {
        if (bIndex==-1 || (boxes[i].length < boxes[bIndex].length && boxes[i].width < boxes[bIndex].width))
        {
            maximumHeight = max(maximumHeight, findMaxHeight(boxes, i, i-1)+ boxes[i].height);
        }
    }

    return dp[index] = maximumHeight;
}

int maxStackHeight(int H[], int W[], int L[], int N)
{
    vector<Box> boxes;

    for(int i=0; i<N; i++)
    {
        boxes.push_back({max(L[i],W[i]), min(L[i],W[i]), H[i]});
        boxes.push_back({max(H[i],W[i]), min(H[i],W[i]), L[i]});
        boxes.push_back({max(H[i],L[i]), min(H[i],L[i]), W[i]});
    }

    memset(dp, -1, sizeof(dp));

    sort(boxes.begin(), boxes.end(), compare);

    return findMaxHeight(boxes, -1, boxes.size()-1);
}

int main()
{
    int L[] = { 4, 1, 4, 10 };
    int W[] = { 6, 2, 5, 12 };
    int H[] = { 7, 3, 6, 32 };
    int N = sizeof(L)/sizeof(L[0]);

    int maxHeight = maxStackHeight(H,L,W,N);
    cout<<"Max Stack Height = "<<maxHeight;

    return 0;
}

