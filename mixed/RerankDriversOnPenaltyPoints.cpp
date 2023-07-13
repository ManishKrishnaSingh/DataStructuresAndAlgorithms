#include<bits/stdc++.h>

using namespace std;

/********************************************************************************
Below is the ranking of Car drivers in a Car race:
Ranking: B A C D F E
Penalty: 6 5 0 3 5 4
Here, in example, B is ranked first but has earned 6 Penalty Points.

Based on the Penalty Points, a drivers can move upto P positions if he earns less
PenaltyPoints than his predecessor. So, the updated ranking shall be as below:
Ranking: C D A E F B
Penalty: 0 3 5 4 5 6
*********************************************************************************/

void rerankCarDrivers(vector<pair<char,int>>& drivers, int P)
{
	int n = drivers.size();
	int idx=1, curr, count;
	while(idx < n)
	{
		count = P;
		curr  = idx;
		while(curr >= 1 and count-- > 0 and drivers[curr-1].second > drivers[curr].second)
		{
			swap(drivers[curr-1], drivers[curr]); curr--;
		}
		idx++;
	}
}

int main()
{
	vector<pair<char,int>> rankOfDrivers = 
	{
		{'B', 6},
		{'A', 5},
		{'C', 0},
		{'D', 3},
		{'F', 5},
		{'E', 4}
	};

	rerankCarDrivers(rankOfDrivers, 2);

	for(auto& data : rankOfDrivers)
	{
		cout<<"{"<<data.first<<","<<data.second<<"} ";
	}

	return 0;
}

/****************************
Time Complexity  : O(N*P))
Space Complexity : O(1)
*****************************/