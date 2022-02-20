#include <iostream>

using namespace std;

int nByThreeRepeatNumber(int arr[], int n){
    int candidate[2];
    int count[2] = {0};

    for(int i=0; i<n; i++){
        if(arr[i] == candidate[0]){
            count[0]++;
        } else if(arr[i] == candidate[i]){
            count[1]++;
        } else if(count[0] == 0){
            count[0]++;
            candidate[0] = arr[i];
        } else if(count[1] ==0){
            count[1]++;
            candidate[1] = arr[i];
        } else {
            count[0]--;
            count[1]--;
        }
    }

    count[0] = 0;
    count[1] = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == candidate[0]){
            count[0]++;
            if(count[0] > n/3){
                return candidate[0];
            }
        }
        if(arr[i] == candidate[1]){
            count[1]++;
            if(count[1] > n/3){
                return candidate[1];
            }
        }
    }

    return -1;
}

int main(){
    int arr[] = {4, 3, 5, 5, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    int result=nByThreeRepeatNumber(arr,n);
    cout<<"N/3 Repeat Elements = "<<result;

    return 0;
}

