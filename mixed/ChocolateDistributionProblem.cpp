#include <bits/stdc++.h>

using namespace std;

int getMinDiff(int choco[], int n, int student){
	if(n < student){
		return -1;
	}

	int result = INT_MAX;

	sort(choco, choco+n);

	for(int i=0; i+student-1 < n; i++){
		int diff = choco[i+student-1] - choco[i];
		if(diff < result){
			result = diff;
		}
	}

	return result;
}

int main(){
    int choco[] = {12,4,7,9,2,23,25,41,30,40,28,42,30,44,48,43,50};
    int student = 7;

    int n = sizeof(choco) / sizeof(choco[0]);
    cout << "Minimum difference = "<< getMinDiff(choco, n, student);

    return 0;
}

