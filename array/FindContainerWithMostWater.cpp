#include <bits/stdc++.h>

using namespace std;

/** Container With Most Water */
int maxArea(vector<int>& height){
    int area = 0;
    int left=0, right=height.size()-1;
    while (left < right){
        area = max(area, min(height[left],height[right]) * (right-left));
        if (height[left] < height[right]){
            left++;
        } else {
            right--;
        }
    }
    return area;
}

int main(){
    vector<int> height={1, 5, 4, 3};
    cout<<"Area = "<<maxArea(height);
    return 0;
}