#include <bits/stdc++.h>

using namespace std;

/***************************************************************************
Given the following :
- Heights: A list of heights of N persons standing in a queue
- Infront: A list of numbers corresponding to each person (P) that gives
  the number of persons who are taller than P and standing in front of P
Return,
- List of actual order of persons’s height
***************************************************************************/

/**Pair {height, infront}*/
typedef pair<int,int> Node;

bool compare(Node& left, Node& right){
    if(left.first != right.first){
        return left.first > right.first;
    }
    return left.second < right.second;
}

vector<Node> orderOfPeopleHeights(vector<int>& heights, vector<int>& infront){
    int n = heights.size();

    vector<Node> people;
    for(int i=0; i<n; i++){
        people.push_back({heights[i], infront[i]});
    }

    sort(people.begin(), people.end(), compare);

    vector<Node> order;
    for(int i=0; i < people.size(); i++){
        order.insert(order.begin()+people[i].second, people[i]);
    }
    return order;
}

int main() {
    vector<int> heights = {5,3,2,6,1,4};
    vector<int> infront = {0,1,2,0,3,2};

    auto order = orderOfPeopleHeights(heights, infront);

    cout<<"Correct order of people: ";
    for(int i = 0; i < order.size(); i++){
        cout<<"{"<<order[i].first<<","<<order[i].second<<"} ";
    }

    return 0;
}