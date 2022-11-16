#include <bits/stdc++.h>

using namespace std;

int kModulo = 1000000007; //modulo 10^9 + 7.

unsigned long multiInverse(unsigned long x, int y)
{
    unsigned long tot = 1, p = x;
    for (; y; y >>= 1) 
    {
        if (y & 1){
            tot = (tot * p) % kModulo;
        }
        p = (p * p) % kModulo;
    }
    return tot;
}

class Fancy
{
    int index;
    long multiply;
    long increment;
    long sequence[100001];

  public:
    Fancy()
    {
        this->index = 0;
        this->multiply = 1;
        this->increment = 0;
    }

    void append(int value)
    {
        sequence[index++] = (((kModulo+value-increment)%kModulo) * multiInverse(multiply,kModulo-2))%kModulo;
    }

    void addAll(int num)
    {
        increment = (increment+ num%kModulo) % kModulo;
    }

    void multAll(int num)
    {
        multiply  = (multiply  * num%kModulo) % kModulo;
        increment = (increment * num%kModulo) % kModulo;
    }

    int getIndex(int idx)
    {
        if (idx >= index)
        {
            return -1;
        }
        else
        {
            return ((sequence[idx]*multiply) % kModulo + increment) % kModulo;
        }
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