#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> subsets(vector<int> arr){
	vector<vector<int>> res;

	int N = arr.size();

	vector<int> subset;
	for(int i=0; i<(1<<N); i++){
		subset.clear();
		for(int j=0; j<N; j++){
			if(i & (1<<j)){
				subset.push_back(arr[j]);
			}
		}
		res.push_back(subset);
	}
	return res;
}

int main(){
    vector<int> array = { 1, 2, 3 };
    vector<vector<int> > res = subsets(array);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

