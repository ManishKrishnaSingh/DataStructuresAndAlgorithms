#include <bits/stdc++.h>

using namespace std;

int findLongestConsecutiveSequence(int nums[], int n) {
    unordered_set<int> hash;
    for(int i=0; i<n; i++) {
        hash.insert(nums[i]);
    }

    int maxLength = 0;
    for(int num : hash) {
        if (hash.find(num-1)==hash.end()) {
            int currLength = 1;
            int currentNum = num;
            while(hash.find(currentNum+1)!=hash.end()) {
                currentNum += 1;
                currLength += 1;
            }
            maxLength = max(maxLength, currLength);
        }
    }
    return maxLength;
}

int main() {
    int arr[] = {9,1,4,7,3,1,0,5,8,-1,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int length = findLongestConsecutiveSequence(arr, n);
    cout<<"Length [Longest Consecutive Sequence] = "<<length;

    return 0;
}

