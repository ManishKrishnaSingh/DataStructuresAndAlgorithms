#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int key)
{
    if(!nums.empty())
    {
        int n = nums.size();
        int left=0, right=n-1;

        int mid;
        while(left <= right)
        {
            mid = (left+right) >> 1;
            if(nums[mid] == key)
            {
                return mid;
            }

            if(nums[left] <= nums[mid]) // left side sorted
            {
                if(key < nums[mid] and key >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else // right side sorted
            {
                if(key > nums[mid] and key <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
    }

    return -1;
}

int searchRecursive(vector<int>& nums, int low, int high, int key)
{
    int mid = (low+high) >> 1;
    if(nums[mid] == key)
    {
        return mid;
    }

    // this case is added for low+1 == high
    if(low==mid && (nums[mid] != key || nums[mid+1] != key))
    {
        return -1;
    }

    if(nums[low] < nums[mid])
    {
        // left side sorted
        if(key < nums[mid])
        {
            return searchRecursive(nums, low, mid, key);
        }
        else
        {
            return searchRecursive(nums, mid, high, key);
        }
    }
    else
    {
        // right side sorted
        if(key > nums[mid])
        {
            return searchRecursive(nums, mid, high, key);
        }
        else
        {
            return searchRecursive(nums, low, mid, key);
        }
    }

    return -1;
}

int main()
{
    vector<int> input = { 4, 5, 6, 7, 8, 9, 1, 2 };

    int key = 7, index = -1, n = input.size();

    index = search(input, key);
    if (index != -1){
        cout << "Key found at Index: " << index << endl;
    } else {
        cout << "Key is not found in the array!" << endl;
    }

    index = searchRecursive(input, 0, n-1, key);
    if (index != -1){
        cout << "Key found at Index: " << index << endl;
    } else {
        cout << "Key is not found in the array!" << endl;
    }

    return 0;
}