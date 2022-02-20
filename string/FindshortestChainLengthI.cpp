#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct node {
	string word;
	int wLength;
}Node;

bool IsDifferByOneChar(string x, string y){
    int count = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != y[i]){
            count++;
            if (count > 1){
                return false;
            }
        }
    }
    return true;
}

int getLadderLength(string start, string final, vector<string>& words){
    queue<Node> sQueue;
    queue<Node> fQueue;

    unordered_map<string, int> svisited;
    unordered_map<string, int> fvisited;

    Node beg = {start, 1};
    Node end = {final, 1};

    sQueue.push(beg);
    svisited[start]=1;

    fQueue.push(end);
    fvisited[final]=1;

    while (!sQueue.empty() && !fQueue.empty()) {
        Node snode = sQueue.front();
        sQueue.pop();

        for (auto it = words.begin(); it != words.end(); it++) {
            if (IsDifferByOneChar(snode.word, *it) && svisited.count(*it) == false) {
                Node temp = { *it, snode.wLength + 1 };
                sQueue.push(temp);
                svisited[*it] = snode.wLength + 1;

                if (temp.word == final) {
                    return temp.wLength;
                }

                if (fvisited.count(temp.word)) {
                    return temp.wLength + fvisited[temp.word] - 1;
                }
            }
        }

        Node fnode = fQueue.front();
        fQueue.pop();

        for (auto it = words.begin(); it != words.end(); it++) {
            if (IsDifferByOneChar(fnode.word, *it) && fvisited.count(*it) == false) {
                Node temp = { *it, fnode.wLength + 1 };
                fQueue.push(temp);
                fvisited[*it] = fnode.wLength + 1;

                if (temp.word == start) {
                    return temp.wLength;
                }

                if (svisited.count(temp.word)) {
                    return temp.wLength + svisited[temp.word] - 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    vector<string> words;
    words.push_back("poon");
    words.push_back("plee");
    words.push_back("same");
    words.push_back("poie");
    words.push_back("plie");
    words.push_back("poin");
    words.push_back("plea");

    string start = "toon";
    string final = "plea";

    cout<<"Length [WL] = "<<getLadderLength(start, final, words)<<endl;

    return 0;
}

