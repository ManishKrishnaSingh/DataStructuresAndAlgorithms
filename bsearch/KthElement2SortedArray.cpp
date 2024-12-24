#include <climits>
#include <iostream>

using namespace std;

int kthElement(int arr1[], int arr2[], int X, int Y, int K){
	if(X > Y){
		return kthElement(arr2, arr1, Y, X, K);
	}

	int low  = max(0, K-Y); // Asuming, we need to take a minimum from array 1 # Lets say K is bigger than Y
	int high = min(K, X);   // Asuming, we cant take all elements from array 1 # Lets say K is bigger than X

	while(low <= high){
		int partitionX = (low+high) >> 1;
		int partitionY = K - partitionX;

		int maxLeftX = (partitionX == 0) ? INT_MIN : arr1[partitionX-1];
		int maxLeftY = (partitionY == 0) ? INT_MIN : arr2[partitionY-1];

		int minRightX = (partitionX == X) ? INT_MAX : arr1[partitionX];
		int minRightY = (partitionY == Y) ? INT_MAX : arr2[partitionY];

		if(maxLeftX <= minRightY && maxLeftY <= minRightX){
			return max(maxLeftX, maxLeftY);
		} else if(maxLeftX > minRightY){
			high = partitionX - 1;
		} else {
			low = partitionX + 1;
		}
	}
	return -1;
}


int main(){
	int arr1[5] = {2, 3, 6, 7, 9};
	int arr2[4] = {1, 4, 8, 10};

	int K = 5;
	int X = sizeof(arr1)/sizeof(int);
	int Y = sizeof(arr2)/sizeof(int);

	cout << "Kth Element = " << kthElement(arr1, arr2, X, Y, K) << endl;

	return 0;
}

