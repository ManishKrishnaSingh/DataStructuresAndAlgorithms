#include <iostream>

using namespace std;

bool isPossible(int barn[], int n, int cows, int diff){
	int curr = barn[0];
	int numOfCows = 1;
	for(int i=1; i<n; i++){
		if((barn[i] - curr) >= diff){
			curr = barn[i];
			numOfCows++;
		}
		if(numOfCows == cows){
			return true;
		}
	}
	return false;
}

int solveAggressiveCows(int barn[], int n, int cows){
	if(n < cows){
		return -1;
	}

	int result = 0;

	int low = 1;
	int high = barn[n-1] - barn[0];
	while(low <= high){
		int mid = (low+high) >> 1;
		if(isPossible(barn, n, cows, mid)){
			result = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return result;
}

int main(){
	int barn[] = {1,2,4,8,9};
	int cows = 3;

	int n = sizeof(barn)/sizeof(barn[0]);

	int largestMinimum = solveAggressiveCows(barn, n, cows);
	cout<<"Largest Minimum Difference = "<<largestMinimum<<endl;

	return 0;
}

