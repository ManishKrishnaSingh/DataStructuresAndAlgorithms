#include <iostream>

using namespace std;

#define DELIMITER '\n'

string findLastLines(string iStr, int n){
    string oStr=iStr;
    if(n > 0){
        int count = 0;
        size_t idx = iStr.find_last_of(DELIMITER);
        if(idx != string::npos){
            while(count < n){
                while(idx > 0 && iStr[idx]!=DELIMITER){
                    idx--;
                }
                if(idx > 0 && iStr[idx]==DELIMITER){
                    idx--; count++;
                } else {
                    break;
                }
            }
            if(idx > 0){
                oStr = iStr.substr(idx+2);
            }
        }
    }
    return oStr;
}

int main(void){
	string str1 = "";
	string str2 = "\n";
	string str3 = "L1\nL2\nL3\nL4\nL5\nL6\nL7\nL8";
	string str4 = "L1\nL2\nL3\nL4\nL5\nL6\nL7\nL8\nL9\nL10\nL11\nL12";

	cout<<findLastLines(str1, 10)<<endl;
	cout<<"---------------------"<<endl;
	cout<<findLastLines(str2, 10)<<endl;
	cout<<"---------------------"<<endl;
	cout<<findLastLines(str3, 10)<<endl;
	cout<<"---------------------"<<endl;
	cout<<findLastLines(str4, 10)<<endl;
	cout<<"---------------------"<<endl;

	return 0;
}

