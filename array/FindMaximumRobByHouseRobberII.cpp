#include <bits/stdc++.h>

using namespace std;

int maxRobUtil(vector<int>& nums, int start, int end){
    int robOne=0,robTwo=0,maxRob=0;
    for(int i=start; i <= end; i++){
        maxRob = max(robOne+nums[i], robTwo);
        robOne = robTwo;
        robTwo = maxRob;
    }
    return maxRob;
}

int maxRob(vector<int>& nums){
    int n = nums.size();
    if(n == 0){
        return 0;
    } else if (n == 1){
        return nums[0];
    } else if (n == 2){
        return max(nums[0], nums[1]);
    }
    return max(maxRobUtil(nums,0,n-2), maxRobUtil(nums,1,n-1));
}

int main(){
    vector<int> nums1 = {2,3,2};
    cout<<"\nMax Rob = "<<maxRob(nums1);

    vector<int> nums2 = {1,2,3,1};
    cout<<"\nMax Rob = "<<maxRob(nums2);

    vector<int> nums3 = {1,2,3};
    cout<<"\nMax Rob = "<<maxRob(nums3);

    return 0;
}