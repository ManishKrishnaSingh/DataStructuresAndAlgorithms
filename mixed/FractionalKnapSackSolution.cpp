#include <bits/stdc++.h>

using namespace std;

//Item -> { Weight, Value }
typedef pair<int,int> Item;

bool compare(Item x, Item y)
{
    // compare rate (value/weight) of two items
    double xRate = (double)x.second/(double)x.first;
    double yRate = (double)y.second/(double)y.first;

    return xRate > yRate;
}

double knapSack(vector<Item> items, double weight){
    int n = items.size();
    sort(items.begin(), items.end(), compare);

    double result = 0.0;
    double wtOfItem, vlOfItem;
    for(int i=0; i<n; i++) {
        wtOfItem = items[i].first;
        vlOfItem = items[i].second;

        if (wtOfItem <= weight) {
            // add complete item
            weight -= wtOfItem;
            result += vlOfItem;
        } else {
            //add the fractional part of the item
            result += vlOfItem * (weight/wtOfItem);
            break; // break as by now sack is full
        }
    }

    return result;
}

int main()
{
    //Sack Capacity
    double weight = 50;
    
    //List of {Weight,Value}
    vector<Item> items = {
        {10,60}, {20,100}, {30,120}
    };
    
    int maxValue = knapSack(items, weight);
    cout<<"Max KnapSack Value = "<<maxValue;

    return 0;
}