#include <bits/stdc++.h>

using namespace std;

/*********************************************************************************************
A matching in a Bipartite Graph is a set of edges chosen in such a way that no two edges share
an endpoint. A maximum matching is a matching of maximum size (maximum number of edges).

In a maximum matching, if any edge is added to it, it is no longer a matching. There can be more
than one maximum matchings for a given Bipartite Graph.

Example Usecase,
There are M applicants & N jobs. Each applicant has a subset of jobs that he/she is interested
in. Each job opening can only accept one applicant & a job applicant can be appointed for only
one job. Find assignment of jobs to applicants in such that as maximum applicants get jobs.
**********************************************************************************************/

bool dfsBipartiteMatch(vector<vector<bool>>& graph, int applicant, vector<bool>& visit, vector<int>& assignedJob)
{
    // Total number of jobs
    int N = assignedJob.size();

    // Try every job one by one
    for(int job = 0; job < N; job++)
    {
        if(graph[applicant][job] && !visit[job])
        {
            visit[job] = true;

            if(assignedJob[job] == -1 || dfsBipartiteMatch(graph, assignedJob[job], visit, assignedJob))
            {
                assignedJob[job] = applicant; return true;
            }
        }
    }

    return false;
}

int maxBipartiteMatching(vector<vector<bool>>& graph)
{
    if(graph.size()==0 || graph[0].size()==0)
    {
        return 0;
    }

    int M = graph.size();    // applicants
    int N = graph[0].size(); // no of jobs

    vector<bool> visit(N,false);
    vector<int> assignedJob(N,-1);

    int assignedJobCount = 0;
    for(int u = 0; u < M; u++)
    {
        visit.assign(N, false); // reset visit flags

        if(dfsBipartiteMatch(graph, u, visit, assignedJob))
        {
            assignedJobCount++;
        }
    }

    return assignedJobCount;
}

int main()
{
    vector<vector<bool>> graph=
    {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1}
    };

    cout<<"Maximum applicants that gets job = "<<maxBipartiteMatching(graph);

    return 0;
}

/************************
Time Complexity  : O(V*E)
Space Complexity : O(V+E)
*************************/