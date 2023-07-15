#include <bits/stdc++.h>

using namespace std;

const int LINELENGTH = 6;

void solveWordWrap(vector<int>& arrLength)
{
    int n = arrLength.size();

    int solution[n];
    int linecost[n];

    // update last line
    solution[n-1] = n-1;

    int i,j,curLength,curCost;
    for (i = n-2; i >= 0; i--)
    {
        curLength   = -1;
        linecost[i] = INT_MAX;

        for (j = i; j < n; j++)
        {
            curLength += (arrLength[j] + 1);

            if (curLength > LINELENGTH)
            {
                break;
            }

            if (j == n-1)
            {
                curCost = 0;
            }
            else
            {
                curCost = pow((LINELENGTH-curLength),3) + linecost[j+1];
            }

            if (curCost < linecost[i])
            {
                solution[i] = j;
                linecost[i] = curCost;
            }
        }
    }

    int index = 0;
    while (index < n)
    {
        cout<<index<<"-"<<solution[index]<<"\n";
        index = solution[index] + 1;
    }
}

int main()
{
    vector<int> arrLength = { 3, 2, 2, 5 };

    solveWordWrap(arrLength);

    return 0;
}

/************************
Time Complexity  : O(N^2)
Space Complexity : O(N)
*************************/