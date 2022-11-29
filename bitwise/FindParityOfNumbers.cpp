#include <bits/stdc++.h>

using namespace std;

/**********************************************
Example, find the parity of n = 150 = 1001 0110

Now, divide this number into 2 parts & xor them
Example, n = n ^ (n >> 4) = 1001 ^ 0110 = 1111

Continue, this way until all bits are covered.
**********************************************/

bool hasOddParity(int x)
{
    x = x ^ (x >> 1);
    x = x ^ (x >> 2);
    x = x ^ (x >> 4);
    x = x ^ (x >> 8);
    x = x ^ (x >> 16);

    if (x & 1)
    {
        return true;
    }

    return false;
}

int main()
{
    if(hasOddParity(1227))
    {
        cout<<"Odd Parity\n";
    }
    else
    {
        cout<<"Even Parity\n";
    }

    return 0;
}