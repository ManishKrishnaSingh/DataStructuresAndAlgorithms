#include <bits/stdc++.h>

using namespace std;

int maxRectangle(int histogram[], int n){
	stack<int> stk;

	int stkTop;
	int areaWithStkTop = 0;
	int areaMaxRectangle = 0;

	int i = 0;
	while (i < n){
		if (stk.empty() || histogram[stk.top()] <= histogram[i]){
			stk.push(i++);
		} else {
			stkTop=stk.top(); stk.pop();
			areaWithStkTop = histogram[stkTop] * (stk.empty() ? i : i-stk.top()-1);
			areaMaxRectangle = max(areaWithStkTop, areaMaxRectangle);
		}
	}

	while (!stk.empty()){
		stkTop=stk.top(); stk.pop();
		areaWithStkTop = histogram[stkTop] * (stk.empty() ? i : i-stk.top()-1);
		areaMaxRectangle = max(areaWithStkTop, areaMaxRectangle);
	}

	return areaMaxRectangle;
}

int main(){
	int histogram[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(histogram)/sizeof(histogram[0]);

	cout << "Area [Largest Rectangle] = "<< maxRectangle(histogram, n);

	return 0;
}

