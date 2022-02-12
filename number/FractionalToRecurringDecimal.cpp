#include <map>
#include <vector>
#include <iostream>

using namespace std;

string fractionalToRecurringDecimal(int N, int D){
	if(N==0 && D!=0){
		return "0";
	}
	if(D==0){
		return "INF";
	}

	vector<char> res;
	if((N > 0 and D < 0) || (N < 0 && D > 0)){
		res.push_back('-');
		N = abs(N);
		D = abs(D);
	}

	int quotient =  N/D;
	string str = to_string(quotient);
	for(char c : str){
		res.push_back(c);
	}

	int reminder = N%D;
	if(reminder != 0){
		res.push_back('.');
		map<int, int> m;

		while(reminder != 0){
			if(m.find(reminder) != m.end()){
				res.insert(res.begin()+m[reminder], '(');
				res.push_back(')'); break;
			} else {
				m[reminder] = res.size();
				reminder = reminder*10;
				res.push_back('0'+(reminder/D));
				reminder = reminder % D;
			}
		}
	}
	return string(res.begin(), res.end());
}

int main(){
	int N = 4;
	int D = 3;

	string res = fractionalToRecurringDecimal(N, D);
	cout<<"Result = "<<res<<endl;

	return 0;
}

