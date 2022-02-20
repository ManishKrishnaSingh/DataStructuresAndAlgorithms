#include <iostream>

using namespace std;

void findPrimes(int n){
    bool IsPrime[n+1];
    for(int i=0; i<=n; i++){
        IsPrime[i] = true;
    }

    IsPrime[0] = IsPrime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(IsPrime[i]){
            for(int j=2; i*j<=n; j++){
                IsPrime[i*j] = false;
            }
        }
    }

    cout<<"Prime Numbers:";
    for(int i=2; i<=n; i++){
        if(IsPrime[i]){
            cout<<" "<<i;
        }
    }
}

int main(){
    int num = 100;
    findPrimes(num);

    return 0;
}

// Prime Numbers: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97. #O(n*log(log(n)))
// n/2 + n/3 + n/5 + n/7 + n/11 + n/13 + n/17 + n/19 + n/23 + n/29 + n/31 + n/37 + n/41 +.. = n*log(log(n))
