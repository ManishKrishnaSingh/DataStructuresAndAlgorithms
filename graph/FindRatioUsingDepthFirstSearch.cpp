#include <bits/stdc++.h>

using namespace std;


unordered_map<string, unordered_map<string,double>> mapRatio;


typedef struct data
{
    string x, y;
    double ratio;
}Data;


void storeRatioData(vector<Data>& input)
{
    mapRatio.clear();
    for(auto& item : input)
    {
        mapRatio[item.x][item.y] = item.ratio;

        // set reverse ratio
        if(item.ratio == 0)
        {
            mapRatio[item.y][item.x] = DBL_MAX;
        }
        else
        {
            mapRatio[item.y][item.x] = 1/item.ratio;
        }
    }
}


bool dfs(string a, string b, double& currRatio, unordered_set<string>& visited)
{
  visited.insert(a);

  if(mapRatio[a].count(b))
  {
      currRatio = currRatio * mapRatio[a][b]; return true;
  }
  else
  {
    for(auto& item : mapRatio[a])
    {
      if(visited.count(item.first) == 0 and mapRatio[a][item.first] != 0 and mapRatio[a][item.first] != DBL_MAX)
      {
        currRatio = currRatio * mapRatio[a][item.first];

        if(dfs(item.first, b, currRatio, visited))
        {
          return true;
        }

        currRatio = currRatio / mapRatio[a][item.first];
      }
    }
  }
  return false;
}


double findRatio(string a, string b)
{
  if(mapRatio.count(a) and mapRatio.count(b))
  {
    if(mapRatio[a].count(b))
    {
       return mapRatio[a][b];
    }
    else
    {
      unordered_set<string> visited;

      double currRatio = 1;
      if(dfs(a, b, currRatio, visited))
      {
          return currRatio;
      }
    }
  }

  return DBL_MAX;
}


int main()
{
    vector<Data> input =
    {
        {"A", "B", 123},
        {"X", "Y",  23},
        {"Y", "Z", 345},
        {"Z", "W",   0},
        {"Z", "M",   1}
    };
   
    storeRatioData(input);

    cout<<"Ratio [A/B] = "<<findRatio("A", "B")<<endl;
    cout<<"Ratio [X/W] = "<<findRatio("X", "W")<<endl;
    cout<<"Ratio [X/Z] = "<<findRatio("X", "Z")<<endl;
    cout<<"Ratio [Z/X] = "<<findRatio("Z", "X")<<endl;

    return 0;
}


