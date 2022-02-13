#include <bits/stdc++.h>

using namespace std;

string fractionToDecimal(int numerator, int denominator){
    string result;
    map<int, int> m;

    int reminder = numerator%denominator;
    while(reminder!=0 && m.find(reminder)==m.end()){
                m[reminder] = result.length();
                reminder = reminder*10;
                result += to_string((int)(reminder/denominator));
                reminder = reminder%denominator;
    }

    if(reminder==0){
        result = "No recurring sequence";
    } else {
        result = result.substr(m[reminder]);
    }

    return result;
}

int main(){
    int numr = 50, denr = 22;
    string res=fractionToDecimal(numr, denr);
    cout<<"Recurring sequence = ["<<res<<"]";
    return 0;
}

