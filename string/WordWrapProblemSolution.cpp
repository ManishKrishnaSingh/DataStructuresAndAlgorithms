#include <bits/stdc++.h>

using namespace std;

#define LL 6

void solveWordWrap(int arr[], int n){
    int linecost[n];
    int solution[n];

    // update last line
    solution[n-1] = n-1;

    int currCost, currlength;
    for (int j=n-2; j>=0; j--)
    {
        currlength = -1;
        linecost[j] = INT_MAX;
        for (int i=j; i<n; i++)
        {
            currlength += (arr[i]+1);
            if (currlength > LL)
                break;

            if (i == n-1)
                currCost = 0;
            else
                currCost = pow((LL-currlength),3) + linecost[i+1];

            if (currCost < linecost[j])
            {
                linecost[j] = currCost;
                solution[j] = i;
            }
        }
    }

    int idx = 0;
    while (idx < n){
        cout<<idx<<"-"<<solution[idx]<<endl;
        idx = solution[idx] + 1;
    }
}

int main(){
    int arr[] = { 3, 2, 2, 5 };
    int n = sizeof(arr)/sizeof(int);

    solveWordWrap(arr, n);

    return 0;
}