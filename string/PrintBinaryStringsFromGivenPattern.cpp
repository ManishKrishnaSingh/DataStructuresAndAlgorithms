#include <list>
#include <iostream>

using namespace std;

void printBinaryStrings(string str){
    if(!str.empty()){
        list<string> list;
        list.push_back(str);

        while(!list.empty()){
            string front = list.front();
            list.pop_front();

            auto idx = front.find('?');
            if(idx != string::npos){
                front[idx] = '0';
                list.push_back(front);

                front[idx] = '1';
                list.push_back(front);
            } else {
                 cout<<front<<endl;
            }
        }
    }
}

int main(){
    string str = "1??0?101";

    printBinaryStrings(str);

    return 0;
}


