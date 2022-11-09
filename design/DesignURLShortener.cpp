#include <bits/stdc++.h>

using namespace std;

class TinyURL
{
    string baseurl, alphabet;
    // store short key for long URL in map
    unordered_map<string,string> mKeyToURL;

  public:
    TinyURL(string iBaseURL)
    {
        srand(time(0)); //init random number generators
        this->baseurl  = iBaseURL;
        this->alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    string getRand()
    {
        string urlKey(8,'*');
        for (int i=0; i<8; i++) {
            urlKey[i] = alphabet[rand()%62];
        }
        return urlKey;
    }

    string encode(string longUrl)
    {
        string key = getRand();
        while (mKeyToURL.count(key))
        {
            key = getRand();
        }
        mKeyToURL[key] = longUrl;
        return (baseurl+key);
    }

    string decode(string shortUrl)
    {
        return mKeyToURL[shortUrl.substr(baseurl.size())];
    }
};

int main()
{
    TinyURL appTinyURL("http://tinyurl.com/");
    
    string tinyUrl = appTinyURL.encode("https://github.com/ManishKrishnaSingh/");
    std::cout << "Tiny URL = " << tinyUrl << std::endl;

    string longUrl = appTinyURL.decode(tinyUrl);
    std::cout << "Long URL = " << longUrl << std::endl;

    return 0;
}