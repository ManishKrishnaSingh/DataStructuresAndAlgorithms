#include <bits/stdc++.h>

using namespace std;

class MovingAverage
{
    int window;
    double winsum;
    queue<double> nums;

  public:
    MovingAverage(int size)
    {
        winsum = 0.0;
        window = size;
    }

    double next(int value)
    {
        nums.push(value);
        winsum += value;
        if(nums.size() > window)
        {
            winsum -= nums.front();
            nums.pop();//pop front
        }
        return winsum/nums.size();
    }
};

int main(){
    cout<<"Moving Average:-\n";

    MovingAverage movingAverage(3);
    cout<<"\nCurrent Average = "<<movingAverage.next(1); // 1.0
    cout<<"\nCurrent Average = "<<movingAverage.next(10);// 5.5
    cout<<"\nCurrent Average = "<<movingAverage.next(3); // 4.66667
    cout<<"\nCurrent Average = "<<movingAverage.next(5); // 6.0

    return 0;
}