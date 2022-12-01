#include <bits/stdc++.h>

using namespace std;

#define LL 6

void solveWordWrap(int arr[], int n){
    int linecost[n];
    int solution[n];

    // update last line
    solution[n-1] = n-1;

    int currCost, currlength;
    for (int i=n-2; i>=0; i--)
    {
        currlength = -1;
        linecost[i] = INT_MAX;
        for (int j=i; j<n; j++)
        {
            currlength += (arr[j]+1);
            if (currlength > LL)
                break;

            if (j == n-1)
                currCost = 0;
            else
                currCost = pow((LL-currlength),3) + linecost[j+1];

            if (currCost < linecost[i])
            {
                linecost[i] = currCost;
                solution[i] = j;
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