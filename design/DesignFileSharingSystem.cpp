#include <bits/stdc++.h>

using namespace std;

class FileSharingSystem {
    int maxUserId = 0;
    set<int> availableUserIds;
    unordered_map<int, set<int>> mChunkToUsers;
    unordered_map<int, vector<int>> mUserToChunks;

  public:
    FileSharingSystem(int m) {}
    
    int join(vector<int> userOwnedChunks)
    {
        int userId = -1;
        // find new user id to assign
        if(availableUserIds.size() == 0){
            userId = ++maxUserId;
        } else {
            userId = *(availableUserIds.begin());
            availableUserIds.erase(availableUserIds.begin());
        }

        //assign owned chunks to userId
        mUserToChunks[userId] = userOwnedChunks;
        //assign owned userId to chunks
        for(auto chunk : userOwnedChunks)
        {
            mChunkToUsers[chunk].insert(userId);
        }

        return userId;
    }
    
    void leave(int userId) {
        // add user id to available id list
        availableUserIds.insert(userId);
        // clear users from user map
        mUserToChunks[userId].clear(); 
        // clear user id from chunk map
        for(auto chunk: mUserToChunks[userId])
        {
            mChunkToUsers[chunk].erase(userId);
        }
    }
    
    vector<int> request(int userId, int chunkId)
    {
        vector<int> userIds;
        // assign chunk id to the given user id
        mUserToChunks[userId].push_back(chunkId);
        // add all user id for that chunk
        if(mChunkToUsers[chunkId].size() > 0)
        {
            for(int aUserId : mChunkToUsers[chunkId])
            {
                userIds.push_back(aUserId);
            }
        }
        return userIds;
    }
};

int main()
{
    cout<<"File Sharing System\n";

    FileSharingSystem fss(4);

    cout<<fss.join({1,2})<<endl;
    cout<<fss.join({2,3})<<endl;
    cout<<fss.join({4})<<endl;

    fss.request(1,3);
    fss.request(2,2);

    fss.leave(2);

    fss.request(2,1);

    cout<<fss.join({})<<endl;

    return 0;
}