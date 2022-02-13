#include <deque>
#include <iostream>

using namespace std;

void maxSlidingWindow(int arr[], int n, int k){
    std::deque<int> w;

    int i;
    for (i = 0; i < k; ++i){
        while(!w.empty() && arr[i] >= arr[w.back()]){
            w.pop_back();
        }
        w.push_back(i);
    }

    for (; i < n; ++i){
        cout << arr[w.front()] << " ";

        while(!w.empty() && w.front() <= i-k){
            w.pop_front();
        }

        while(!w.empty() && arr[i] >= arr[w.back()]){
            w.pop_back();
        }

        w.push_back(i);
    }
    cout << arr[w.front()] << endl;
}

int main(){
    int arr[] = {12,1,78,90,57,89,56};
    int n = sizeof(arr) / sizeof(int);

    int window = 3;
    maxSlidingWindow(arr, n, window);

    return 0;
}

