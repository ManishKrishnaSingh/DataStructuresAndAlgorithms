#include <bits/stdc++.h>

using namespace std;

double nthRoot(int x, int y){
    double low, high;
    if(x >= 0 && x < 1){
        low = x;
        high = 1;
    } else {
        low = 1;
        high = x;
    }

    double diff = 0.00001;

    double mid = (low+high)/2;
    while(abs(x-pow(mid,y)) >= diff){
        if(pow(mid,y) > x){
            high = mid;
        } else {
            low = mid;
        }
        mid = (low + high)/2;
    }
    return mid;
}

int main(){
    int x = 5, y = 2;

    cout<<"ROOT[5,2] = "<<nthRoot(x, y);

    return 0;
}

