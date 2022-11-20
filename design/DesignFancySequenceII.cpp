#include <bits/stdc++.h>

using namespace std;

// modulo=10^9+7 : Prime Number
unsigned long kMod = 1000000007;

/*****************************************************
 * If we use a prime number as our modulus kMod, then
 * Inverse Modulo of mul is pow(mul, kMod - 2) % kMod
*****************************************************/

class Fancy
{
    vector<unsigned long> sequence;
    vector<unsigned long> inc, mul;

  public:
    Fancy()
    {
        this->inc = {0};
        this->mul = {1};
    }

    void append(int iKey)
    {
        sequence.push_back(iKey);
        inc.push_back(inc.back());
        mul.push_back(mul.back());
    }

    void addAll(int iKey)
    {
        inc.back() += iKey;
    }

    void multAll(int iKey)
    {
        inc.back() *= iKey;
        mul.back() *= iKey;
    }

    int getIndex(int idx)
    {
        long result = -1;
        if (idx < sequence.size())
        {
            unsigned long multiplier = mul.back() / mul[idx];
            unsigned long increament = inc.back() - inc[idx] * multiplier;
            result = ((sequence[idx] * multiplier)%kMod + increament) % kMod;
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