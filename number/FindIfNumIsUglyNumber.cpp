#include <iostream>

using namespace std;

int uglyUtil(int a, int b){
    if(a%b == 0){
        a = a/b;
    }
    return a;
}

bool checkUgly(int num){
    num = uglyUtil(num, 2);
    num = uglyUtil(num, 3);
    num = uglyUtil(num, 5);
    return (num==1) ? true : false;
}

bool isUgly(int num){
    if(num <= 0){
        return false;
    }
    if(num == 1){
        return true;
    }
    return checkUgly(num);
}

int main(){
    bool result = isUgly(15);
    cout<<"Is ugly: "<<result<<endl;
    return 0;
}

