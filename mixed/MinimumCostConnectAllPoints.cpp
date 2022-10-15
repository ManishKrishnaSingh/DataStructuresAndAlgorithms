#include<bits/stdc++.h>

using namespace std;

/** pair {distance,dst} */
typedef pair<int,int> Node;

/** Manhattan Distance */
/** MD [(x1,y1), (x2,y2)] = |x1 - x2| + |y1 - y2| */

int minimumCostConnectPoints(vector<vector<int>>& points){
    int minCost = 0;
    int n = points.size();

    // graph edge container
    vector<vector<Node>> edges(n);

    // add graph edges
    int x1, y1, x2, y2, d;
    for(int i=0; i<n; i++){
        x1 = points[i][0];
        y1 = points[i][1];
        for(int j=i+1; j<n; j++){
            x2 = points[j][0];
            y2 = points[j][1];
            // manhattan distance
            d = abs(x1-x2)+abs(y1-y2);
            // add bidirectional edge
            edges[i].push_back({d, j});
            edges[j].push_back({d, i});
        }
    }

    //find min cost
    bool visited[n];
    memset(visited,false, n);

    //create min heap with distance and edge end index
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push({0,0});
    
    int idx, dst;
    while(!pq.empty()){
        auto top=pq.top();pq.pop();
        dst = top.first; //distance
        idx = top.second;//end index

        if(!visited[idx]){
            // mark visited
            visited[idx] = true;
            // add to the cost
            minCost = minCost+dst;
            // visit connected edges
            for(auto node : edges[idx]){
                if(!visited[node.second]){
                    pq.push(node);//add to queue
                }
            }
        }
    }

    return minCost;
}

int main(){
    vector<vector<int>> points = {
        {0,0}, {2,2}, {3,10}, {5,2}, {7,0}
    };

    int minCost = minimumCostConnectPoints(points);
    cout<<"Min Cost To Connect Points = "<<minCost;

    return 0;
}
