#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
    vector<int> list;
    unordered_map<int,int> map;

  public:
    RandomizedSet(){
        srand(time(0));
    }

    bool insert(int iKey){
        if(map.count(iKey)){
            return false;
        } else {
            // add to the list
            list.push_back(iKey);
            // store key index in map
            map[iKey] = list.size()-1;
            return true;
        }
    }

    bool remove(int iKey){
        if(map.find(iKey) == map.end()){
            return false;
        } else {
            // replace ikey with key @ back of list
            int back = list.back(); list.pop_back();
            // update map and list
            map[back] = map[iKey];
            list[map[iKey]] = back;
            // remove from map
            map.erase(iKey);
            return true;
        }
    }

    int getRandom(){
        return list[rand() % list.size()];
    }
};

int main()
{
    cout<<"Randomized Set"<<endl;

    RandomizedSet rs;

    rs.insert(10);
    rs.insert(21);
    rs.insert(11);
    rs.insert(45);
    rs.insert(34);

    rs.remove(11);

    cout<<"random number:"<<rs.getRandom()<<endl;
    cout<<"random number:"<<rs.getRandom()<<endl;

    return 0;
}