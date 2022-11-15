#include <bits/stdc++.h>

using namespace std;

class Codec {
  public:
    string encode(vector<string> vStr)
    {
        string result = "";
        for(string str : vStr)
        {
            result += to_string(str.size()) + "@" + str;
        }
        return result;
    }

    vector<string> decode(string iStr)
    {
        vector<string> result;

        int curr = 0;
        while (curr < iStr.size())
        {
            int pos = iStr.find_first_of('@', curr);
            int len = stoi(iStr.substr(curr, pos-curr));
            curr = pos+1; // update current str pos
            result.push_back(iStr.substr(curr, len));
            curr += len; // add substr length into pos
        }

        return result;
    }
};

int main(){
    Codec codec;

    string strEncoded = codec.encode({"Hello","World"});
    cout << "Encoded String = " << strEncoded << endl;

    cout << "Decoded String = ";
    for(auto strDecoded : codec.decode(strEncoded))
    {
        cout << "->" << strDecoded;
    }

    return 0;
}