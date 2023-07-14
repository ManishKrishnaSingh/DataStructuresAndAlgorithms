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

bool dfs(string a, string b, vector<string>& path, unordered_set<string>& visited)
{
  visited.insert(a);

  if(mapRatio[a].count(b))
  {
      path.push_back(b); return true;
  }
  else
  {
    for(auto& item : mapRatio[a])
    {
      if(visited.count(item.first) == 0)
      {
        path.push_back(item.first);

        if(dfs(item.first, b, path, visited))
        {
          return true;
        }

        path.pop_back();
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
      vector<string> path = {a};
      unordered_set<string> visited;

      if(dfs(a, b, path, visited) and path.back() == b)
      {
          double currRatio = 1;
          int n = path.size();
          for(int i=0; i<n-1; i++)
          {
              if(mapRatio[path[i]][path[i+1]] == DBL_MAX)
              {
                  return DBL_MAX;
              }
              currRatio = currRatio * mapRatio[path[i]][path[i+1]];
          }
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


/****************************
Graph with V Nodes + E Edges
*****************************
Time Complexity  : O(V+E))
Space Complexity : O(V)
*****************************/