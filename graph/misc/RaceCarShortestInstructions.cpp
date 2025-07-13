// https://leetcode.com/problems/race-car/

#include <bits/stdc++.h>

using namespace std;

typedef struct car
{
    int position, speed;

    car(int p, int s):position(p),speed(s){}

    bool operator==(const car& icar) const
    {
        return this->position == icar.position && this->speed == icar.speed;
    }
} Car;

template<>
struct std::hash<Car>
{
    size_t operator()(const Car& iCar) const
    {
        return std::hash<int>()(iCar.position) ^ std::hash<int>()(iCar.speed);
    }
};

int raceCar(int target)
{
    queue<Car> queue;
    unordered_map<Car, bool> visited;

    Car start(0,1);

    queue.push(start);
    visited[start] = true;

    int steps = 0;
    while(!queue.empty())
    {
        int sz = queue.size();
        while(sz--)
        {
            Car curr = queue.front();
            queue.pop();

            if(curr.position == target)
            {
                return steps;
            }

            // A -> Accelerate the Car
            Car next = Car(curr.position + curr.speed, curr.speed * 2);
            if(!visited[next])
            {
                queue.push(next);
                visited[next] = 1;
            }

            // R -> Reverse the Car
            if((curr.position + curr.speed > target and curr.speed > 0) || (curr.position + curr.speed < target and curr.speed < 0))
            {
                Car next = Car(curr.position, curr.speed > 0 ? -1 : 1);
                if(!visited[next])
                {
                    queue.push(next);
                    visited[next] = 1;
                }
            }
        }

        steps++;
    }

    return 0;
}

int main()
{
    cout << "Length [Shortest sequence of instructions] = " << raceCar(3) << endl;
    cout << "Length [Shortest sequence of instructions] = " << raceCar(6) << endl;

    return 0;
}
