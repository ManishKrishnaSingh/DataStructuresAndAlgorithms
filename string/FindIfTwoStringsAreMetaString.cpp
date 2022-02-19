#include <set>
#include <vector>
#include <iostream>

using namespace std;

bool metaStringCheck(string str1, string str2){
    int l1=str1.length();
    int l2=str2.length();

    if(l1 == l2){
        if(str1 == str2){
            set<char> s;
            for(char c: str1){
                s.insert(c);
            }
            if(s.size()<l1){
                return true;
            }
        } else {
            vector<int> v;
            for(int i=0; i<l1; i++){
                if(str1[i] != str2[i]){
                    v.push_back(i);
                }
            }
            if(v.size() == 2 && str1[v[0]] == str2[v[1]] && str1[v[1]]==str2[v[0]]){
                return true;
            }
        }
    }

    return false;
}

int main(){
    string str1 = "fooboo";
    string str2 = "boofoo";

    bool result = metaStringCheck(str1,str2);
    cout<<"Are Meta = "<<boolalpha<<result<<endl;

    return 0;
}

