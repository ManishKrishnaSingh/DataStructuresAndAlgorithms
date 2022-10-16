#include <bits/stdc++.h>

using namespace std;

/***************************************************************************
We are given an array asteroids of integers representing asteroids in a row.
For each of the asteroid:
    - Value represents its size
    - Sign represents its direction
    - Each asteroid moves at the same speed
Find out the state of the remaining asteroids after all the collisions.
***************************************************************************/

template <typename T>
void PrintList(vector<T> v){
    cout<<"[ ";
    for(auto data : v){
        cout<<data<<" ";
    }
    cout<<"]"<<endl;
}

vector<int> asteroidCollision(vector<int>& asteroids){
    stack<int> stk;
    vector<int> result;

    for(auto asteroid : asteroids){
        if(asteroid > 0){
            stk.push(asteroid);
        } else {
            // remove the asteroid from stack top in case of the collision
            while(!stk.empty() and stk.top() > 0 and stk.top() < abs(asteroid)){
                stk.pop();
            }

            if(stk.empty() or stk.top() < 0){
                stk.push(asteroid);
            } else if(stk.top() == abs(asteroid)){
                stk.pop();
            }
        }
    }

    while(!stk.empty()){
        // add remaining asteroids in result
        result.push_back(stk.top());stk.pop();
    }

    // reverse result to print in order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> asteroids = { 5, 10, -5 };
    PrintList(asteroidCollision(asteroids));
    return 0;
}