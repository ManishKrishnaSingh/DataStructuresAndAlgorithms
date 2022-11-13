#include <bits/stdc++.h>

using namespace std;

class StockPrice {
    int latestTime;
    //stock prices (ascending order)
    map<int, int> mPriceToFrequency;
    // hash map timestamp and the stock price
    unordered_map<int, int> mTimestampToPrice;

  public:
    StockPrice()
    {
        latestTime = 0;
    }

    void update(int timestamp, int price)
    {
        // update latestTime to latest value
        latestTime = max(latestTime, timestamp);
        // correct price for previous timestamp
        if (mTimestampToPrice.count(timestamp))
        {
            // remove previous recieved incorrect price
            int oldPrice = mTimestampToPrice[timestamp];
            // reduce old price frequence
            mPriceToFrequency[oldPrice]--;
            // remove the entry from the map
            if (mPriceToFrequency[oldPrice] == 0)
            {
                mPriceToFrequency.erase(oldPrice);
            }
        }
        //increase price frequency
        mPriceToFrequency[price]++;
        // add latest price for the timestamp
        mTimestampToPrice[timestamp] = price;
    }

    int current()
    {
        return mTimestampToPrice[latestTime];
    }

    int maximum()
    {
        return mPriceToFrequency.rbegin()->first;
    }

    int minimum()
    {
        return mPriceToFrequency.begin()->first;
    }
};

int main() {
    cout<<"Stock Price Fluctuation";

    StockPrice stockPrice;

    stockPrice.update(1, 10);
    stockPrice.update(2, 5); cout<<endl;
    cout<<"\ncurrent="<<stockPrice.current();
    cout<<"\nmaximum="<<stockPrice.maximum();
    cout<<"\nminimum="<<stockPrice.minimum();

    stockPrice.update(1, 3);cout<<endl;
    cout<<"\ncurrent="<<stockPrice.current();
    cout<<"\nmaximum="<<stockPrice.maximum();
    cout<<"\nminimum="<<stockPrice.minimum();

    stockPrice.update(4, 2);cout<<endl;
    cout<<"\ncurrent="<<stockPrice.current();
    cout<<"\nmaximum="<<stockPrice.maximum();
    cout<<"\nminimum="<<stockPrice.minimum();

    return 0;
}