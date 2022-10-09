#include <bits/stdc++.h>

using namespace std;

/************************************************
Given an array arr[] of size n. Find if the array
has 3 elements in indices i,j & k such that i<j<k 
and arr[i] < arr[j] > arr[k] and arr[i] < arr[k].
************************************************/

bool find132Pattern(int arr[], int n){
    if(n>=3){
        //pair of num, minLeft
        stack<pair<int,int>> stk;

        int minLeft = arr[0];
        for(int i=1; i<n; i++){
            while(!stk.empty() and arr[i] >= stk.top().first){
                stk.pop();
            }

            if(!stk.empty() and arr[i] >= stk.top().second){
                return true;
            }

            stk.push({arr[i], minLeft});
            minLeft = min(minLeft, arr[i]);
        }
    }
    return false;
}

int main() {
    int arr[] = { 4, 7, 11, 5, 13, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bool has132Pat = find132Pattern(arr,n);
    cout<<"Has 132 Pattern = "<<has132Pat;

    return 0;
}