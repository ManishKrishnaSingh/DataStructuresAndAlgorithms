#include <bits/stdc++.h>

using namespace std;

class Leaderboard
{
    // hash map {player, score}
    unordered_map<int,int> mScore;
    // ordered set {score, player}
    set<pair<int,int>> sScorePlayer;

  public:
    Leaderboard()
    {
        //TODO:
    }

    void addScore(int player, int score)
    {
        sScorePlayer.erase({mScore[player],player});
        mScore[player] += score; //update the score
        sScorePlayer.insert({mScore[player],player});
    }

    int top(int K)
    {
        int totalScore = 0;

        int counter = 0;
        for(auto iter=sScorePlayer.rbegin(); iter!=sScorePlayer.rend() && counter++ < K; iter++)
        {
            totalScore += (iter->first);
        }

        return totalScore;
    }

    void reset(int player)
    {
        sScorePlayer.erase({mScore[player],player});
        mScore[player] = 0; // reset the score to 0
    }
};

int main()
{
    cout<<"Leaderboard:\n";
    Leaderboard leaderboard;

    leaderboard.addScore(1,73);
    leaderboard.addScore(2,56);
    leaderboard.addScore(3,39);
    leaderboard.addScore(4,51);
    leaderboard.addScore(5,4);
    cout<<"\nScore = "<<leaderboard.top(1); // 73

    leaderboard.reset(1);
    leaderboard.reset(2);
    leaderboard.addScore(2,51);
    cout<<"\nScore = "<<leaderboard.top(3); //51+51+39

    return 0;
}