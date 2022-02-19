#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool isNumber(const string iStr){
    return (iStr.find_first_not_of("[0123456789]")==string::npos);
}

vector<string> split(string iStr){
    vector<string> list;
    string line;
    stringstream ss(iStr);
    while(getline(ss, line, '.')){
        list.push_back(line);
    }
    return list;
}

bool IsIpValid(string iStr){
    vector<string> list = split(iStr);
    if (list.size() != 4) {
        return false;
    }
    for (string str: list){
        if (!isNumber(str) || stoi(str)<0 || stoi(str)>255) {
            return false;
        }
    }
    return true;
}

int main(){
    string ip1 = "128.0.0.1";
    string ip2 = "125.16.100.1";
    string ip3 = "125.512.100.1";
    string ip4 = "125.512.100.abc";

    cout<<"Is IP Valid: "<<boolalpha<<IsIpValid(ip1)<<endl;
    cout<<"Is IP Valid: "<<boolalpha<<IsIpValid(ip2)<<endl;
    cout<<"Is IP Valid: "<<boolalpha<<IsIpValid(ip3)<<endl;
    cout<<"Is IP Valid: "<<boolalpha<<IsIpValid(ip4)<<endl;

    return 0;
}

