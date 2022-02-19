#include <iostream>

using namespace std;

bool isPossible(int books[], int n, int student, int maxPages){
	int numOfStudent = 1;
	int curr_pages = 0;
	for(int i=0; i<n; i++){
		if(books[i] > maxPages){
			return false;
		}

		if((books[i]+curr_pages) > maxPages){
			numOfStudent++;
			curr_pages = books[i];
		} else {
			curr_pages += books[i];
		}

		if(numOfStudent > student){
			return false;
		}
	}
	return true;
}

int findMinimumPages(int books[], int n, int student){
	if(student > n){
		return -1;
	}

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += books[i];
	}

	int result = 0;

	int low=0, mid, high=sum;
	while(low<=high){
		mid = (low+high) >> 1;
		if(isPossible(books, n, student, mid)){
			result = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return result;
}

int main(){
	int books[] = {12, 34, 67, 90};
	int student = 2;

	int n = sizeof(books)/sizeof(books[0]);

	int minimumPages = findMinimumPages(books, n, student);
	cout<<"Minimum Pages = "<<minimumPages<<endl;

	return 0;
}

