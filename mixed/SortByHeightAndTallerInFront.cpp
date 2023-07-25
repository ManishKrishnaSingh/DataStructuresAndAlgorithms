#include <bits/stdc++.h>

using namespace std;

/*********************************************************************************************
We have a random list of people, where each person knows his own height and the number of tall
people in front of him. Write a code to make the equivalent queue. Example,

Person = {name:string, height:int, TallerInFront:int}

Input:
{"A",6,2}, {"B",1,4}, {"C",11,0}, {"D",5,1}, {"E",10,0}, {"F",4,0}

Output:
{"F",4,0}, {"E",10,0}, {"D",5,1}, {"C",11,0}, {"B",1,4}, {"A",6,2} || {"F","E","D","C","B","A"}
**********************************************************************************************/

struct Person
{
    string name;
    int height;
    int TallerInFront;
};

struct Comparator
{
    bool operator()(Person& x, Person& y)
    {
        if(x.height != y.height)
        {
            return x.height > y.height;
        }
        return x.TallerInFront < y.TallerInFront;
    }
};

vector<Person> buildQueue(vector<Person>& persons)
{
    sort(persons.begin(), persons.end(), Comparator());

    vector<Person> vOrder;
    for(auto& person : persons)
    {
        vOrder.insert(vOrder.begin()+person.TallerInFront, person);
    }

    return vOrder;
}

int main()
{
    vector<Person> persons=
    {
        {"A", 6,  2},
        {"B", 1,  4},
        {"C", 11, 0},
        {"D", 5,  1},
        {"E", 10, 0},
        {"F", 4,  0}
    };

    for(auto& person : buildQueue(persons))
    {
        cout<<"{"<<person.name<<",\t"<<person.height<<",\t"<<person.TallerInFront<<"}\n";
    }

    return 0;
}

/************************
Time Complexity  : O(N^2)
Space Complexity : O(N)
*************************/
