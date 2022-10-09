#include <bits/stdc++.h>

using namespace std;

class TimeBasedKeyValueStore {
  private:
    unordered_map<string,vector<pair<int,string>>> mKeyValue;

  public:
    TimeBasedKeyValueStore(){
        mKeyValue.clear();
    }

    void set(string key, string value, int timestamp){
        mKeyValue[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp){
        string ans = "";
        auto vList = mKeyValue[key];

        int low=0, mid, high=vList.size()-1;
        while(low <= high){
            mid = (low+high) >> 1;
            if(vList[mid].first <= timestamp){
                ans = vList[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main(){
    TimeBasedKeyValueStore kvStore;

    kvStore.set("foo","bar",1);
    cout << kvStore.get("foo", 1) << endl;
    cout << kvStore.get("foo", 3) << endl;

    kvStore.set("foo","boo",4);
    cout << kvStore.get("foo", 4) << endl;
    cout << kvStore.get("foo", 5) << endl;

    return 0;
}