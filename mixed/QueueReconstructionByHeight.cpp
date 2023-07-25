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

struct Person
{
    int PersonHeight;
    int TallerInFront;
};

bool compare(const Person& lftPerson, const Person& rhtPerson)
{
    if(lftPerson.PersonHeight != rhtPerson.PersonHeight)
    {
        return lftPerson.PersonHeight > rhtPerson.PersonHeight;
    }
    return lftPerson.TallerInFront < rhtPerson.TallerInFront;
}

vector<Person> orderOfPeopleHeights(vector<int>& PersonHeights, vector<int>& TallerInFront)
{
    int n = PersonHeights.size();

    vector<Person> listPeople;
    for(int i=0; i<n; i++)
    {
        listPeople.push_back({PersonHeights[i], TallerInFront[i]});
    }

    sort(listPeople.begin(), listPeople.end(), compare);

    vector<Person> orderOfPeople;
    for(auto& person : listPeople)
    {
        orderOfPeople.insert(orderOfPeople.begin()+person.TallerInFront, person);
    }

    return orderOfPeople;
}

int main()
{
    vector<int> PersonHeights = {5,3,2,6,1,4};
    vector<int> TallerInFront = {0,1,2,0,3,2};

    cout<<"Correct order of people: ";
    for(auto& person: orderOfPeopleHeights(PersonHeights,TallerInFront))
    {
        cout<<"{"<<person.PersonHeight<<","<<person.TallerInFront<<"} ";
    }

    return 0;
}

/************************
Time Complexity  : O(N^2)
Space Complexity : O(N)
*************************/
