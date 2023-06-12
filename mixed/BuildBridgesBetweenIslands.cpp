/***********************************************************************************************
 Build bridges between Islands
 ***********************************************************************************************
 Imagine N * M map. Each tile can be of 2 types: water or land.
 Map is constructed in a way that it has some number of island of random shape.

 You task is to connect all islands with bridges in a cost effective way. Basically it means
 that you should be able to travel from island A to island Z by using bridges and other islands.
 ***********************************************************************************************
 Input: N * M matrix - represents map
 Ouput: Array[Pair[Pair[x1, y1], Pair[x2, y2]], Pair...]
************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int M = 6, N = 5;

typedef pair<int,int> Point;  // Pair of coordinates of cells
typedef pair<int,int> Bridge; // Pair of start and end indexes

vector<pair<int,int>> directions =
{
	{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}
};

bool IsSafe(int x, int y)
{
	if(x>=0 and x<M and y>=0 and y<N)
	{
		return true;
	}
	return false;
}

void dfs(int map[M][N], int i, int j, bool visited[M][N])
{
	visited[i][j] = true;

	for(auto& direction : directions)
	{
		int x = i + direction.first;
		int y = j + direction.second;
		if(IsSafe(x,y) and map[x][y]==1 and !visited[x][y])
		{
			dfs(map, x, y, visited);
		}
	}
}

vector<Point> findIslands(int map[M][N])
{
	vector<Point> islands;

	bool visited[M][N];
	memset(visited, false, sizeof visited);

	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map[i][j]==1 and !visited[i][j])
			{
				islands.push_back({i,j});
				dfs(map, i, j, visited);
			}
		}
	}

	return islands;
}

class MinSpanningTreeGraph
{
	int V;
	list<pair<int,int>> *adj;
public:
	MinSpanningTreeGraph(int iV): V(iV)
	{
		adj = new list<pair<int,int>>[V];
	}

	void addEdge(int u, int v, int w)
	{
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	vector<Point> minimumSpanningTree()
	{
		vector<int>  parent(V, -1);
		vector<int>  weight(V, INT_MAX);
		vector<bool> visited(V, false);

		// pair of weight and vertex
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

		pq.push({0,0}); // start with vertex 0

		int u, v, w;
		while(!pq.empty())
		{
			u = pq.top().second; pq.pop();

			visited[u] = true;
			for(auto iter=adj[u].begin(); iter!=adj[u].end(); iter++)
			{
				v = iter->first;
				w = iter->second;
				if(!visited[v] and weight[v] > w)
				{
					weight[v] = w;
					parent[v] = u;
					pq.push({w,v});
 				}
			}
		}

		vector<Bridge> bridges;
		for(int v=0; v<V; v++)
		{
			if(parent[v] != -1)
			{
				bridges.push_back({parent[v], v});
			}
		}

		return bridges;
	}
};

int distance(Point& x, Point& y)
{
	return sqrt((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second));
}

vector<pair<Point,Point>> buildBridge(int map[M][N])
{
	vector<pair<int,int>> islands = findIslands(map);

	int i,j,nIslands = islands.size();

	MinSpanningTreeGraph graph(nIslands);
	for(i = 0; i < nIslands-1; i++)
	{
		for(j = i+1; j < nIslands; j++)
		{
			graph.addEdge(i, j, distance(islands[i], islands[j]));
		}
	}

	vector<Bridge> bridgeIndexes = graph.minimumSpanningTree();

	vector<pair<Point,Point>> bridgesCoordinates;
	for(auto& bridgeIndex : bridgeIndexes)
	{
		bridgesCoordinates.push_back({islands[bridgeIndex.first], islands[bridgeIndex.second]});
	}

	return bridgesCoordinates;
}

int main()
{
	int map[M][N] =
	{
		{1, 1, 0, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{1, 0, 0, 1, 1},
		{1, 1, 0, 1, 1}
	};

	vector<pair<Point,Point>> bridges = buildBridge(map);
	for(auto& bridge : bridges)
	{
		auto& beg = bridge.first;
		auto& end = bridge.second;
		cout<<"["<<beg.first<<","<<beg.second<<"]-["<<end.first<<","<<end.second<<"]"<<endl;
	}

	return 0;
}
