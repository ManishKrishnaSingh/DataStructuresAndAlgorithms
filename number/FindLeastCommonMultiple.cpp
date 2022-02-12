#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b){
    if(a <= 0 || b <= 0){
        return -1;
    }
    return (a/gcd(a,b)) * b;
}

int findLCM(int a, int b){
    if(a <= 0 || b <= 0){
        return -1;
    }

    int x = max(a,b);
    int y = min(a,b);

    int result = -1;
    for(result=x; ; result+=x){
        if(result%y == 0){
            break;
        }
    }
    return result;
}

int main(){
    int a = 14, b = 35;

    cout<<"LCM["<<a<<","<<b<<"] = "<<lcm(a, b)<<endl;
    cout<<"LCM["<<a<<","<<b<<"] = "<<findLCM(a, b)<<endl;

    return 0;
}

