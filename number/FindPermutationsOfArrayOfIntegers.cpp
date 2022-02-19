#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void printPermutation(int* result, int n){
    cout<<"\n=> ";
    for(int i=0; i<n; i++){
        cout<<result[i]<<" ";
    }
}

void permutate(int* digits, int d, int* counts, int n, int* result, int level){
    if(level == n){
        printPermutation(result, n);
    }

    for(int i=0; i<d; i++){
        if(counts[i] == 0){
            continue;
        }

        result[level] = digits[i];

        counts[i]--; // decrease digit count
        permutate(digits, d, counts, n, result, level+1);
        counts[i]++; // backtrack digit count
    }
}

void findUniquePermutations(vector<int> nums){
    unordered_map<int,int> mCount;
    for(int num: nums){
        mCount[num]++;
    }

    int n = nums.size();
    int d = mCount.size();

    int result[n];
    int digits[d];
    int counts[d];

    int index = -1;
    for(auto element: mCount){
        index++;
        digits[index] = element.first;
        counts[index] = element.second;
    }

    permutate(digits, d, counts, n, result, 0);
}

int main(){
    vector<int> nums={1,1,2,3,3};

    cout<<"Unique Permutations:";
    findUniquePermutations(nums);

    return 0;
}

