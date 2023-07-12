#include <bits/stdc++.h>

using namespace std;

typedef struct job
{
	int start;
	int finish;
	int profit;
}Job;

bool compare(const Job& s1, const Job& s2)
{
	if(s1.finish == s2.finish)
	{
		return s1.start < s2.start;
	}
	return (s1.finish < s2.finish);
}

int latestNonConflict(Job arr[], int i)
{
	for (int j=i-1; j>=0; j--)
	{
		if (arr[j].finish <= arr[i-1].start)
		{
			return j;
		}
	}
	return -1;
}

int maxProfitJobScheduling(Job arr[], int n){
	if (n == 1)
	{
		return arr[0].profit;
	}

	// Profit when current job is included
	int inclProf = arr[n-1].profit;
	int i = latestNonConflict(arr, n);
	if (i != -1)
	{
		inclProf += maxProfitJobScheduling(arr, i+1);
	}

	// Profit when current job is excluded
	int exclProf = maxProfitJobScheduling(arr, n-1);

	return max(inclProf, exclProf);
}

int rcMaxProfitJobScheduling(Job arr[], int n)
{
	sort(arr, arr+n, compare);
	return maxProfitJobScheduling(arr, n);
}


int dpMaxProfitJobScheduling(Job jobs[], int n)
{
	sort(jobs, jobs+n, compare);

	vector<int> dp(n);

	dp[0] = jobs[0].profit;

	int i,previousProfit;
	int left, right, mid;
	for(i = 1; i < n; i++)
	{
		dp[i] = dp[i-1];

		previousProfit=0;

		left=0; right=i-1;
		while(left <= right)
		{
			mid = (left+right) / 2;
			if(jobs[mid].finish <= jobs[i].start)
			{
				previousProfit = dp[mid];
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		dp[i] = max(dp[i], previousProfit+jobs[i].profit);
	}

	return dp[n-1];
}


int main()
{
	Job arr[] =
	{
		{3,  10,  20},
		{1,   2,  50},
		{6,  19, 100},
		{2, 100, 200}
	};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<"Optimal profit = "<<rcMaxProfitJobScheduling(arr, n)<<endl;
	cout<<"Optimal profit = "<<dpMaxProfitJobScheduling(arr, n)<<endl;

	return 0;
}

/******************************
Recursive Method:
Time Complexity  : O(N*2^N)
Space Complexity : O(N)

Dynamic Programming:
Time Complexity  : O(N*log(N))
Space Complexity : O(N)
*******************************/
