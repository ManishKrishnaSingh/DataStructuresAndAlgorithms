#include <bits/stdc++.h>

using namespace std;

class BrowserHistory {
    stack<string> stkback;
    stack<string> stkforward;
    string currpage = "";

  public:
    BrowserHistory(string homepage){
        this->currpage = homepage;
    }

    void visit(string iurl){
        if(this->currpage != ""){
            stkback.push(currpage);
        }

        //clear the forward stack
        while(!stkforward.empty())
        {
            stkforward.pop();
        }

        this->currpage = iurl;
    }

    string back(int steps){
        while(!stkback.empty() and steps-- > 0)
        {
            stkforward.push(currpage);
            currpage = stkback.top(); stkback.pop();
        }
        return currpage;
    }

    string forward(int steps){
        while (!stkforward.empty() and steps-- > 0)
        {
            stkback.push(currpage);
            currpage = stkforward.top(); stkforward.pop();
        }
        return currpage;
    }
};

int main() {
    BrowserHistory browser("https://www.google.co.in/");

    browser.visit("https://www.amazon.com");
    browser.visit("https://www.netflix.com");
    browser.visit("https://www.facebook.com");
    browser.visit("https://www.microsoft.com");

    cout << browser.back(3) << endl;
    cout << browser.forward(2) << endl;

    return 0;
}