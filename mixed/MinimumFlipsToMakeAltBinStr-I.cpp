#include <bits/stdc++.h>

using namespace std;

char flip(char ch)
{
    return (ch == '0') ? '1' : '0';
}

int minFlipsToAltBinStr(string str, char ch)
{
    int numOfFlips = 0;
    int strLen=str.length();
    for(int i=0; i<strLen; i++)
    {
        if (str[i] != ch)
        {
            numOfFlips++;
        }
        ch = flip(ch); //flip
    }
    return numOfFlips;
}

int minFlipsToAltBinStr(string str)
{
    return min(minFlipsToAltBinStr(str, '0'), minFlipsToAltBinStr(str, '1'));
}

int main()
{
    cout<<"\nMinimum flips = "<<minFlipsToAltBinStr("010");
    cout<<"\nMinimum flips = "<<minFlipsToAltBinStr("1110");
    cout<<"\nMinimum flips = "<<minFlipsToAltBinStr("111000");
    cout<<"\nMinimum flips = "<<minFlipsToAltBinStr("0001010111");	

    return 0;
}