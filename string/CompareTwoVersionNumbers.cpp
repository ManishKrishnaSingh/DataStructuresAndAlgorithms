#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

/*
Version compare problem
 10.5.6.1  >  10.5.5.1
 10.5.7.1  <  10.6.2.1
 7.14.2    =  7.14.2.0.0.0.2.0
*/

vector<string> stringTokenizer(string iStr){
    string str;
    stringstream ss(iStr);
    vector<string> tokens;
    while(getline(ss, str, '.')){
        tokens.push_back(str);
    }
    return tokens;
}

string higherVersion(string v1, string v2){
    vector<string> a1 = stringTokenizer(v1);
    vector<string> a2 = stringTokenizer(v2);

    int l1 = a1.size();
    int l2 = a2.size();
    int minLen = min(l1, l2);

    int idx, left, right;
    for(idx=0; idx<minLen; idx++){
        left  = stoi(a1[idx]);
        right = stoi(a2[idx]);
        if(left > right){
            return v1;
        } else if(left < right){
            return v2;
        }
    }

    int num;
    if(idx < l1){
        while(idx < l1){
            num = stoi(a1[idx]);
            if(num > 0){
                return v2;
            }
            idx++;
        }
    } else if(idx < l2){
        while(idx < l2){
            num = stoi(a2[idx]);
            if(num > 0){
                return v2;
            }
            idx++;
        }
    }
    return "";
}

int main() {
    cout<<"Higher Version :-> "<<higherVersion("10.5.6.1", "10.5.5.1")<<endl;
    cout<<"Higher Version :-> "<<higherVersion("10.5.7.1", "10.6.2.1")<<endl;
    cout<<"Higher Version :-> "<<higherVersion("7.14.2.0", "7.14.2.0.0.0.2.0")<<endl;

    return 0;
}

