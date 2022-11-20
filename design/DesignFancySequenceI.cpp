#include <bits/stdc++.h>

using namespace std;

// modulo=10^9+7 : Prime Number
unsigned long kMod = 1000000007;

/*****************************************************
 * If we use a prime number as our modulus kMod, then
 * Inverse Modulo of mul is pow(mul, kMod - 2) % kMod
*****************************************************/

long modpow(long x, int y)
{
    long result=1;
    while (y != 0)
    {
        if(y & 1){
            result = (result*x) % kMod;
        }

        x = (x*x) % kMod;
        y = y >> 1;//shift
    }
    return result;
}

class Fancy
{
    long inc, mul;
    vector<long> seq;

  public:
    Fancy()
    {
        this->mul = 1;
        this->inc = 0;
    }

    void append(int value)
    {
        seq.push_back((((kMod+value-inc)%kMod) * modpow(mul,kMod-2))%kMod);
    }

    void addAll(int num)
    {
        inc = (inc+ num%kMod) % kMod;
    }

    void multAll(int num)
    {
        mul = (mul * num%kMod) % kMod;
        inc = (inc * num%kMod) % kMod;
    }

    int getIndex(int idx)
    {
        long result = -1;
        if (idx < seq.size())
        {
            result = ((seq[idx] * mul) % kMod + inc) % kMod;
        }
        return result;
    }
};

int main()
{
    cout<<"Fancy Sequence"<<endl;
    Fancy fancy;

    fancy.append(2);   // fancy sequence: [2]
    fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
    fancy.append(7);   // fancy sequence: [5, 7]
    fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
    cout<<"\nSequence = "<<fancy.getIndex(0); // return 10

    fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
    fancy.append(10);  // fancy sequence: [13, 17, 10]
    fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
    cout<<"\nSequence = "<<fancy.getIndex(0); // return 26
    cout<<"\nSequence = "<<fancy.getIndex(1); // return 34
    cout<<"\nSequence = "<<fancy.getIndex(2); // return 20

    return 0;
}