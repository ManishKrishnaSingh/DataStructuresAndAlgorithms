#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    bool isfile;
    string content;
    unordered_map<string,node*> mChildren;
    node(){
        this->isfile = false;
        this->content = "";
    }
}TrieNode;

vector<string> split(string strPath){
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

class InMemoryFileSystem {
    TrieNode *root;

public:
    InMemoryFileSystem(){
        root = new TrieNode();
    }

    TrieNode* moveToFolder(string path){
        TrieNode *cur = root;
        auto folders = split(path);
        for(auto folder : folders){
            if (cur->mChildren[folder] == NULL){
                cur->mChildren[folder] = new TrieNode();
            }
            cur = cur->mChildren[folder];
        }
        return cur;
    }

    vector<string> ls(string path){
        vector<string> files;

        TrieNode* curr = moveToFolder(path);
        if(curr != NULL){
            if (curr->isfile){
                // extraxt and add only last file name in the result
                files.push_back(path.substr(path.find_last_of('/')+1));
            } else {
                // add all children node files
                for(auto node: curr->mChildren){
                    files.push_back(node.first);
                }
                // sort files lexicographically 
                sort(files.begin(), files.end());
            }
        }

        return files;
    }

    void mkdir(string path){
        TrieNode* curr = moveToFolder(path);
    }

    void addContentToFile(string filePath, string content){
        TrieNode* curr = moveToFolder(filePath);
        if(curr != NULL){
            curr->isfile   = true;
            curr->content += content;
        }
    }

    string readContentFromFile(string filePath){
        string content = "";
        TrieNode* curr = moveToFolder(filePath);
        if(curr != NULL){
            content = curr->content;
        }
        return content;
    }
};

int main(){
    cout<<"In-memory file system\n";

    InMemoryFileSystem imfs;

    vector<string> files = imfs.ls("/");

    imfs.mkdir("/alpha/beta");
    imfs.mkdir("/alpha/gama");
    for(auto file: imfs.ls("/alpha")){
        cout<<"List Item: "<<file<<endl;
    }

    imfs.addContentToFile("/alpha/beta/myfile", "Say Hello!");
    string fileContent = imfs.readContentFromFile("/alpha/beta/myfile");

    cout<<"In-Memory File Content = "<<fileContent<<endl;

    return 0;
}