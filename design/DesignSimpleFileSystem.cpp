#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int value;
    string name;
    unordered_map<string, node*> mChildren;

    node(string name){
        this->value = -1;
        this->name = name;
    }
}TrieNode;


vector<string> split(string strPath)
{
    vector<string> ans;
    if(!strPath.empty()){
        string line;
        stringstream ss(strPath);
        while(getline(ss, line, '/')){
            if(!line.empty()){
                ans.push_back(line);
            }
        }
    }
    return ans;
}

class SimpleFileSystem {
    TrieNode* root;

  public:
    SimpleFileSystem(){
        this->root = new TrieNode("");
    }

    bool createPath(string path, int value){
        TrieNode* curr = root;
        auto folders = split(path);

        int counter = 0;
        for (string folder: folders){
            ++counter; // increament the counter
            if (curr->mChildren.count(folder)==0){
                // parent path does not exist
                if (counter < folders.size()){
                    return false;
                }
                curr->mChildren[folder] = new TrieNode(folder);
            }
            // move to children folder node
            curr = curr->mChildren[folder];
        }

        // apply path check
        if (curr->value != -1){
            // path exits
            return false;
        } else {
            // path not exists
            curr->value = value;
        }

        return true;
    }

    int get(string path){
        TrieNode* curr = root;
        auto folders = split(path);
        for (string folder: folders){
            // path does not exist
            if (curr->mChildren.count(folder)==0){
                return -1;
            }
            // move to children folder node
            curr = curr->mChildren[folder];
        }
        return curr->value;
    }
};

int main(){
    cout<<"File System\n";

    SimpleFileSystem sfs;

    sfs.createPath("/a",1);
    cout<<"Path Value="<<sfs.get("/a");

    return 0;
}