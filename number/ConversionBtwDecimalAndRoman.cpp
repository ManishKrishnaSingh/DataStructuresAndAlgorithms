#include <bits/stdc++.h>

using namespace std;

string decimalToRoman(int number){
    string str = "";

    int decimals[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    unordered_map<int, string> m = {
        {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10,  "X"}, {9,  "IX"}, {5,  "V"}, {4,  "IV"}, {1,"I"}
    };

    if(number <= 3999){
        int idx = 0;
        while(number){
            while(number/decimals[idx]){
                str += m[decimals[idx]];
                number -= decimals[idx];
            }
            idx++;
        }
    }

    return str;
}

int romanToDecimal(string iStr){
    int number = 0;

    unordered_map<char, int> m = {
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D', 500},{'M',1000}
    };
    
    int sLength = iStr.length();
    for(int idx=0; idx<sLength; idx++){
        int v1 = m[iStr[idx]];
        if(idx+1 < sLength){
            int v2 = m[iStr[idx+1]];
            if(v1 >= v2){
                number += v1;
            } else {
                number += (v2-v1); idx++;
            }
        } else {
            number += v1;
        }
    }

    return number;
}

int main() {
    cout<<"Decimal To Roman:";
    cout<<"\n==> "<<decimalToRoman(1250);
    cout<<"\n==> "<<decimalToRoman(3999);

    cout<<"\n\nRoman To Decimal:";
    cout<<"\n==> "<<romanToDecimal("MCCL");
    cout<<"\n==> "<<romanToDecimal("MMMCMXCIX");

    return 0;
}
