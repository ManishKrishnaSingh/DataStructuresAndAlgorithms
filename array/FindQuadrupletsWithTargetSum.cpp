#include <iostream>
#include <unordered_map>

using namespace std;

void findQuadrupletSum(int arr[], int n, int sumTarget){
    if(n>=4){
        unordered_map<int, pair<int, int>> m;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int sum = arr[i] + arr[j];
                if(m.find(sumTarget-sum) != m.end()){
                    pair<int, int> p = m[sumTarget-sum];
                    if(p.first!=i && p.second!=i && p.first!=j && p.second!=j){
                        cout<<"Solution: ["<<arr[i]<<"+"<<arr[j]<<"+"<<arr[p.first]<<"+"<<arr[p.second]<<"]"<<endl;
                        return;
                    }
                }
                m[arr[i]+arr[j]] = make_pair(i, j);
            }
        }
    }
    cout<<"No Solution!"<<std::endl;
}

int main(){
    int sumTarget = 91;
    int arr[] = { 10, 20, 30, 40, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findQuadrupletSum(arr, n, sumTarget);
    return 0;
}

