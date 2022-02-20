#include <vector>
#include <iostream>

using namespace std;

bool IsPrime(int num){
    if(num <= 1){
        return false;
    }

    if(num <= 3){
        return true;
    }

    if(num%2==0 || num%3==0){
        return false;
    }

    for(int i=5; i*i<=num; i=i+6){
        if(num%i==0 || num%(i+2)==0){
            return false;
        }
    }
    return true;
}

void findPrimes(int num){
    vector<int> primes;
    for(int i=2; i<num; i++){
        if(IsPrime(i)){
            primes.push_back(i);
        }
    }

    cout<<"Prime Numbers:";
    for(int prime: primes){
        cout<<" "<<prime;
    }
}

int main(){
    int num = 100;
    findPrimes(num);

    return 0;
}

