#include <bits/stdc++.h>

using namespace std;

class TopVotedCandidate
{
    map<int, int> mTimeToLeader;

  public:
    TopVotedCandidate(vector<int> persons, vector<int> times)
    {
        int leader = -1;
        unordered_map<int,int> voteCount;
        for (int i=0; i<persons.size(); ++i)
        {
            voteCount[persons[i]]++;
            if(voteCount[persons[i]] >= voteCount[leader])
            {
                leader = persons[i];
            }
            mTimeToLeader[times[i]] = leader;
        }
    }
    int q(int time)
    {
        auto iter = mTimeToLeader.upper_bound(time);
        if(iter != mTimeToLeader.begin())
        {
            return (--iter)-> second;
        }
        return -1;
    }
};

int main(){
    cout<<"Online Election\n";

    vector<int> persons   = {0, 1,  1,  0,  0,  1,  0};
    vector<int> timestamp = {2, 5, 10, 15, 20, 25, 30};

    TopVotedCandidate leadingCandidate(persons,timestamp);

    cout<<"\nLeading Candidate = "<<leadingCandidate.q(0);  //-1
    cout<<"\nLeading Candidate = "<<leadingCandidate.q(3);  // 0
    cout<<"\nLeading Candidate = "<<leadingCandidate.q(12); // 1
    cout<<"\nLeading Candidate = "<<leadingCandidate.q(25); // 1
    cout<<"\nLeading Candidate = "<<leadingCandidate.q(15); // 0
    cout<<"\nLeading Candidate = "<<leadingCandidate.q(24); // 0
    cout<<"\nLeading Candidate = "<<leadingCandidate.q(8);  // 1

    return 0;
}