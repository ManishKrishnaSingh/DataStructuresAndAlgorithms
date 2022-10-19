#include <bits/stdc++.h>

using namespace std;

int maxLoot(vector<int>& nums){
    int n = nums.size();
    if(n == 0){
        return 0;
    } else if (n == 1){
        return nums[0];
    } else if (n == 2){
        return max(nums[0], nums[1]);
    }

    int robOne = nums[0];
    int robTwo = nums[1];
    int maxRob = INT_MIN;
    for(int i=2; i < n; i++){
        maxRob = max(robOne+nums[i], robTwo);
        robOne = robTwo;
        robTwo = maxRob;
    }
 
    return maxRob;
}

int dpMaxLoot(vector<int>& nums){
    int n = nums.size();
    if(n == 0){
        return 0;
    } else if (n == 1){
        return nums[0];
    } else if (n == 2){
        return max(nums[0], nums[1]);
    }

    int dp[n];
    // initialize
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // update table bottom-up
    for(int i=2; i < n; i++){
        dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}

int main(){
    vector<int> nums1 = {1,2,3,1};
    cout<<"\nMax Rob = "<<maxLoot(nums1);
    cout<<"\nMax Rob = "<<dpMaxLoot(nums1);

    vector<int> nums2 = {2,7,9,3,1};
    cout<<"\nMax Rob = "<<maxLoot(nums2);
    cout<<"\nMax Rob = "<<dpMaxLoot(nums2);

    return 0;
}