#include <bits/stdc++.h>

using namespace std;

class ThroneInheritance {
    string king;
    unordered_map<string,bool> mIsDead;
    unordered_map<string,vector<string>> mChildren;

  public:
    ThroneInheritance(string king)
    {
        this->king = king;
    }

    void birth(string parent, string child)
    {
        mChildren[parent].push_back(child);
    }

    void death(string name)
    {
        mIsDead[name] = true;
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> inheritance;
        dfsInheritance(king,inheritance);
        return inheritance;
    }

    void dfsInheritance(string parent, vector<string>& inheritance)
    {
        if(!mIsDead[parent])
        {
            inheritance.push_back(parent);
        }
        for(auto child: mChildren[parent])
        {
            dfsInheritance(child, inheritance);
        }
    }
};

int main(){
    ThroneInheritance throne("king");

    throne.birth("king", "andy");
    throne.birth("king", "bob");
    throne.birth("king", "catherine");
    throne.birth("andy", "matthew");
    throne.birth("bob", "alex");
    throne.birth("bob", "asha");
    cout<<"\nThrone Inheritance Order:";
    for(auto name : throne.getInheritanceOrder())
    {
        cout<<" "<<name;
    }
    

    throne.death("bob");
    cout<<"\nThrone Inheritance Order:";
    for(auto name : throne.getInheritanceOrder())
    {
        cout<<" "<<name;
    }

    return 0;
}