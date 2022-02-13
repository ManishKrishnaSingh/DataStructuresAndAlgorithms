#include <iostream>

using namespace std;

bool hasModularSum(int arr[], int n, int divisor){
    if(n > divisor){
        return true;
    }

    bool dp[divisor]={false};
    for(int i=0; i<n; i++){
        if(dp[0]){
            return true;
        }

        bool temp[divisor] = {false};
        for(int j=0; j<divisor; j++){
            if(dp[j] && dp[(j+arr[i])%divisor]== false){
                temp[(j+arr[i])%divisor] = true;
            }
        }

        for(int j=0; j<divisor; j++){
            if(temp[j]){
                dp[j] = true;
            }
        }

        dp[arr[i]%divisor] = true;
    }
    return dp[0];
}

int main(){
    int divisor = 5;
    int arr[] = {1, 7, 9, 11};
    int n = sizeof(arr)/sizeof(int);

    bool result = hasModularSum(arr, n, divisor);
    cout<<"Has Modular Sum = "<<boolalpha<<result;

    return 0;
}

