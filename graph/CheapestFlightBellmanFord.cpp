#include <bits/stdc++.h>

using namespace std;

/**Apply Bellman-Ford*/

typedef struct flight {
    int s, d, p;//src,dst,price
    flight(int s, int d, int p){
        this->s = s;
        this->d = d;
        this->p = p;
    }
}Flight;

int findCheapestPrice(vector<Flight>& flights, int src, int dst, int stops){
    int noofflights = flights.size();

    int prices[noofflights];
    for(int i=0; i<noofflights; i++){
        prices[i] = INT_MAX;
    }

    prices[src] = 0; // set src to src price
    
    int temp[noofflights];
    for(int k=0; k<=stops; k++){
        //copy curr prices to temp prices
        memcpy(temp, prices, sizeof(prices));

        // minimise flight prices
        for(auto flight : flights){
            if(prices[flight.s] == INT_MAX){
                continue;
            }
            if((prices[flight.s] + flight.p) < temp[flight.d]){
                temp[flight.d] = prices[flight.s] + flight.p;
            }
        }

        //copy temp prices to curr prices
        memcpy(prices, temp, sizeof(temp));
    } 

    return (prices[dst]==INT_MAX ? -1 : prices[dst]);
}

int main() {
    int src=0, dst=3, stops=1;
    vector<Flight> flights = {
        {0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}
    };

    int minCost = findCheapestPrice(flights, src, dst, stops);
    cout<<"Flight Price ["<<stops<<" Stops] = "<<minCost<<endl;

    return 0;
}