#include <bits/stdc++.h>

using namespace std;

class CarParkingSystem {
    vector<int> capacity;

  public:
    CarParkingSystem(int big, int medium, int small)
    {
        capacity = {big, medium, small};
    }

    bool addCar(int carType)
    {
        return capacity[carType-1]-- > 0;
    }
};

int main(){
    cout<<"Car Parking System"<<endl;
    CarParkingSystem cps(10, 20, 25);

    cps.addCar(1);

    return 0;
}