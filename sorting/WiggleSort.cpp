#include <bits/stdc++.h>

using namespace std;

void wiggleSort(vector<int>& nums){
    for(int i=0; i < nums.size()-1; i++){
        if(i%2 == 0){
            // even index compare
            if(nums[i] > nums[i+1]){
                swap(nums[i], nums[i+1]);
            }
        } else {
            // odd index compare
            if(nums[i] < nums[i+1]){
                swap(nums[i], nums[i+1]);
            }
        }
    }
}

void printArray(vector<int>& nums){
    cout<<"\nSorted array:";
    for(auto num : nums){
        cout<<" "<<num;
    }
}

int main() {
    vector<int> nums1 = {1,5,1,1,6,4};
    wiggleSort(nums1);printArray(nums1);

    vector<int> nums2 = {1,3,2,2,3,1};
    wiggleSort(nums2);printArray(nums2);

    vector<int> nums3 = {12,34,54,2,3};
    wiggleSort(nums3);printArray(nums3);

    return 0;
}