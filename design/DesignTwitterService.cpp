#include <bits/stdc++.h>

using namespace std;

typedef struct tweet {
    int tweetId;
    int timestamp;
    tweet* nextTweet;
    tweet(int iTweetId, int iTimestamp){
        this->tweetId   = iTweetId;
        this->timestamp = iTimestamp;
        this->nextTweet = nullptr;
    }
}Tweet;

class compare {
  public:
    bool operator()(const Tweet* t1, const Tweet* t2){
        return t1->timestamp < t2->timestamp;
    }
};

class Twitter{
    int gTweetTime;
    unordered_map<int, Tweet*> tweetHeads;
    unordered_map<int, unordered_set<int>>  following;

  public:
    Twitter(){
        this->gTweetTime = 1;
    }

    void postTweet(int iUserId, int iTweetId){
        Tweet* newTweet = new Tweet(iTweetId, gTweetTime++);
        newTweet->nextTweet = this->tweetHeads[iUserId];
        this->tweetHeads[iUserId] = newTweet;
    }

    vector<int> getNewsFeed(int iUserId){
        vector<int> userFeed;
        priority_queue<Tweet*, vector<Tweet*>, compare>  pq;

        //add own tweets in the timeline
        if(tweetHeads.find(iUserId)!=tweetHeads.end() && tweetHeads[iUserId]!=nullptr){
            pq.push(tweetHeads[iUserId]);
        }

        //add tweets from following users
        for(int user : following[iUserId]){
            if(tweetHeads.find(user)!=tweetHeads.end() && tweetHeads[user]!=nullptr){
                pq.push(tweetHeads[user]);
            }
        }

        int counter = 0;
        //add upto 10 tweets in the news feed
        while(!pq.empty() && counter++ < 10){
            Tweet* curr = pq.top();pq.pop();
            if(curr->nextTweet!=nullptr){
                pq.push(curr->nextTweet);
            }
            userFeed.push_back(curr->tweetId);
        }

        return userFeed;
    }

    void follow(int iFollowerId, int iFolloweeId){
        this->following[iFollowerId].insert(iFolloweeId);
    }

    void unfollow(int iFollowerId, int iFolloweeId){
        this->following[iFollowerId].erase(iFolloweeId);
    }
};

int main() {
    cout<<"Twitter"<<endl;
    return 0;
}