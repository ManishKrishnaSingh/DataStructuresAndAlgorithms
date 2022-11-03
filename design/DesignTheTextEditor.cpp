#include <bits/stdc++.h>

using namespace std;

class TextEditor {
    stack<char> left;
    stack<char> right;

  public:
    void addText(string iText){
        for(auto ch : iText){
            left.push(ch);
        }
    }

    int deleteText(int K) {
        int counter = 0;
        while(!left.empty() and K-- > 0){
            left.pop();
            counter++;
        }
        return counter;
    }

    string cursorLeft(int K){
        while(!left.empty() and K-- > 0){
            right.push(left.top()); left.pop();
        }
        return cursorShiftString();
    }

    string cursorRight(int K) {
        while(!right.empty() and K-- > 0){
            left.push(right.top());right.pop();
        }
        return cursorShiftString();
    }

    // return last min(10, len) chars
    // to the left of the curr cursor
    string cursorShiftString(){
        string str = "";
        int counter = 10;

        // push back to the left stack
        while(!left.empty() and counter-- > 0){
            str += left.top(); left.pop();
        }

        reverse(str.begin(), str.end());

        // push back to the left stack
        for(int i=0; i<str.size(); i++){
            left.push(str[i]);
        }

        return str;
    }
};

int main() {
    TextEditor* editor = new TextEditor();
    editor->addText("MultinationalCompany");

    cout << editor->deleteText(5) << endl;

    cout << editor->cursorLeft(2) << endl;
    cout << editor->cursorRight(3) << endl;

    return 0;
}