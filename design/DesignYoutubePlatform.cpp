#include <bits/stdc++.h>

using namespace std;

class VideoSharingPlatform
{
    unordered_map<int,string> mIdToContents;
    unordered_map<int,int> views, likes, dislikes;
    priority_queue<int,vector<int>,greater<int>> uploadId;

  public:
    VideoSharingPlatform()
    {
        uploadId.push(1);
    }

    int upload(string video)
    {
        // get upload id
        int vid = uploadId.top();
        uploadId.pop();
        // add next upload id
        if (uploadId.empty())
        {
            uploadId.push(vid+1);
        }

        // add video to the content
        mIdToContents[vid] = video;

        // init
        views[vid] = 0;
        likes[vid] = 0;
        dislikes[vid] = 0;

        return vid;
    }

    void remove(int vid) {
        if (mIdToContents.count(vid))
        {
            // erase content
            mIdToContents.erase(vid);
            // ersase attributes
            views.erase(vid);
            likes.erase(vid);
            dislikes.erase(vid);
            // add to available
            uploadId.push(vid);
        }
    }

    string watch(int vid, int start, int end)
    {
        if (mIdToContents.count(vid))
        {
            string content = mIdToContents[vid];
            int length = content.length();
            if (start >= length)
            {
                return "-1";
            }

            views[vid]++;
            return content.substr(start, min(length-1, end)-start+1);
        }
        return "-1";
    }

    void like(int vid) {
        if (likes.count(vid))
        {
            likes[vid]++;
        }
    }

    void dislike(int vid)
    {
        if (dislikes.count(vid))
        {
            dislikes[vid]++;
        }
    }

    vector<int> getLikesAndDislikes(int vid)
    {
        if (mIdToContents.count(vid))
        {
            return {likes[vid], dislikes[vid]};
        }
        return {-1};
    }

    int getViews(int vid)
    {
        if (mIdToContents.count(vid))
        {
            return views[vid];
        }
        return -1;
    }
};

int main()
{
    cout<<"Video Sharing Platform"<<endl;

    VideoSharingPlatform vsp;

    int vid = vsp.upload("Bahubali 1");
    int xyz = vsp.upload("Bahubali 2");

    vsp.remove(xyz);

    string str = vsp.watch(vid, 0, 7);
    cout<<"Watching "<<str<<".."<<endl;

    vsp.like(vid);
    vsp.like(vid);
    vsp.dislike(vid);

    auto attr = vsp.getLikesAndDislikes(vid);

    cout<<"Total views = "<<vsp.getViews(vid)<<endl;
    cout<<"Total likes = "<<attr[0]<<endl;
    cout<<"Total dislikes = "<<attr[1]<<endl;

    return 0;
}