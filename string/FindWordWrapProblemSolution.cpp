#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

#define LL 6

void solveWordWrap(int arr[], int n){
    int cost[n];
    int ansr[n];

    // last line
    ansr[n-1] = 0;
    ansr[n-1] = n-1;

    int currCost;
    int currlength;
    for (int i=n-2; i>=0; i--) {
        cost[i] = INT_MAX;
        currlength = -1;
        for (int j=i; j<n; j++) {
            currlength += (arr[j]+1);
            if (currlength > LL){
                break;
            }

            if (j == n-1){
                currCost = 0;
            } else {
                currCost = pow((LL-currlength),2) + cost[j+1];
            }

            if (currCost < cost[i]) {
                cost[i] = currCost;
                ansr[i] = j;
            }
        }
    }

    int idx=0;
    int line=1;
    while (idx < n) {
        cout<<"Line "<<line++<<" : "<<idx<<"-"<<ansr[idx]<<endl;
        idx = ansr[idx] + 1;
    }
}

int main(){
    int arr[] = { 3, 2, 2, 5 };
    int n = sizeof(arr)/sizeof(int);

    solveWordWrap(arr, n);

    return 0;
}

