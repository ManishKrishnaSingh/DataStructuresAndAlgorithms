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
    int inFront;
};

class Comparator
{
public:
    bool operator()(const Person& x, const Person& y)
    {
        if(x.inFront != y.inFront)
        {
            return x.inFront < y.inFront;
        }
        return x.height > y.height;
    }
};

list<Person> retrieveQueue(vector<Person>& persons)
{
    sort(persons.begin(), persons.end(), Comparator());

    list<Person> pQueue;
    for(auto& person : persons)
    {
        auto iter = pQueue.begin();
        int inFront = person.inFront;

        while(inFront)
        {
            if((*iter).height > person.height)
            {
                inFront--;
            }

            iter++;
        }

        pQueue.insert(iter, person);
    }

    return pQueue;
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

    list<Person> sortedPersons = retrieveQueue(persons);

    for(auto& person : sortedPersons)
    {
        cout<<"{"<<person.name<<",\t"<<person.height<<",\t"<<person.inFront<<"}\n";
    }

    return 0;
}