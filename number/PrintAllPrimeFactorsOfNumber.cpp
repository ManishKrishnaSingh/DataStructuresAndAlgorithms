#include <iostream>

using namespace std;

void findPrimeFactors(int num){
    for(int i=2; i*i<=num; i++){
        while(num%i == 0){
            cout<<" "<<i;
            num = num / i;
        }
    }
    if (num > 2){
        cout<<" "<<num<<endl;
    }
}

int main(){
    int num = 1001;
    cout<<"Prime Factors:";
    findPrimeFactors(num);
    return 0;
}

