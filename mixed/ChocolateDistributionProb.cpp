#include <bits/stdc++.h>

using namespace std;

/*******************************************************************************************
Given an array of N integers where each val represents the number of chocolates in a packet.
Each packet can have a variable number of chocolates and there are m students.

The task is to distribute chocolate packets such that:
- Each student gets one packet.
- The difference between the number of chocolates in the packet with maximum chocolates & the
  packet with minimum chocolates given to the students is minimum.
********************************************************************************************/

int getMinDiff(int choco[], int n, int student)
{
	if(n < student)
	{
		return -1;
	}

	int result = INT_MAX;

	sort(choco, choco+n);

	for(int i=0; i+student-1 < n; i++)
	{
		int diff = choco[i+student-1] - choco[i];

		if(diff < result)
		{
			result = diff;
		}
	}

	return result;
}

int main()
{
    int student = 7;

    int choco[] = {12,4,7,9,2,23,25,41,30,40,28,42,30,44,48,43,50};
    int n = sizeof(choco) / sizeof(choco[0]);

    cout << "Minimum difference = "<< getMinDiff(choco, n, student);

    return 0;
}

/******************************
Time Complexity  : O(N*log(N))
Space Complexity : O(1)
*******************************/