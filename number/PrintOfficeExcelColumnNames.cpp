#include <iostream>

using namespace std;

string findColumnName(int num){
    string str = "";

    int idx;
    while(num > 0){
        idx = (num-1)%26;
        num = (num-1)/26;
        str = char(idx+'A') + str;
    }

    return str;
}

int main(){
    cout<<"Column Name: "<<findColumnName(26)<<endl;
    cout<<"Column Name: "<<findColumnName(69)<<endl;
    cout<<"Column Name: "<<findColumnName(645)<<endl;
    cout<<"Column Name: "<<findColumnName(802)<<endl;
    return 0;
}

