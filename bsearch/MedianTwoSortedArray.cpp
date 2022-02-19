#include <climits>
#include <iostream>

using namespace std;

int getMedian(int arr1[], int arr2[], int x, int y){
	if(x > y){
		return getMedian(arr2, arr1, y, x);
	}

	int low=0, high=x;
	while(low <= high){
		int partitionX = (low+high)/2;
		int partitionY = (x+y+1)/2 - partitionX;

		int maxLeftX  = (partitionX==0) ? INT_MIN : arr1[partitionX-1];
		int minRightX = (partitionX==x) ? INT_MAX : arr1[partitionX];

		int maxLeftY  = (partitionY==0) ? INT_MIN : arr2[partitionY-1];
		int minRightY = (partitionY==y) ? INT_MAX : arr2[partitionY];

		if(maxLeftX <= minRightY && maxLeftY <= minRightX){
			if((x+y)%2 == 0){
				return (max(maxLeftX,maxLeftY) + min(minRightX,minRightY))/2;
			} else {
				return max(maxLeftX, maxLeftY);
			}
		} else if(maxLeftX > minRightY){
			high = partitionX - 1;
		} else {
			low = partitionX + 1;
		}
	}

	return -1;
}

int main(){
    int arr1[] = {900};
    int arr2[] = {5, 8, 10, 20};

    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);

    int median = getMedian(arr1, arr2, n1, n2);
    cout<<"Median [2 sorted array] = "<<median;

    return 0;
}

