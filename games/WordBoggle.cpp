#include <bits/stdc++.h>

using namespace std;

#define M 3
#define N 3

vector<pair<int,int>> directions = {
    {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}
};

typedef struct node{
    bool isLeaf;
    node* children[26];
    node(){
        this->isLeaf = false;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
    }
}Node;

void insert(Node* node, string word){
    int n = word.length();
    Node* pCrawl = node;
    for(int i=0; i<n; i++){
        int index = word[i]-'A';
        if(pCrawl->children[index] == nullptr){
            pCrawl->children[index] = new Node();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isLeaf = true;
}

Node* buildTrie(string dictionary[], int n){
    Node* root = new Node();
    for(int i=0; i<n; i++){
        insert(root, dictionary[i]);
    }
    return root;
}

bool IsSafe(bool visited[M][N], int i, int j){
    return (!visited[i][j] && i<M && i>=0 && j<N && j>=0);
}

void dfs(char boggle[M][N], bool visited[M][N], int i, int j, Node* node, string str)
{
    if(node->isLeaf){
        std::cout << str << std::endl;
    }

    visited[i][j] = true;

    int x, y;
    for(int k=0; k<26; k++){
        if(node->children[k]!=nullptr){
            char ch = (char)('A' + k);
            for(auto d : directions){
                x = i + d.first;
                y = j + d.second;
                if(IsSafe(visited,x,y) && boggle[x][y]==ch)
                {
                    dfs(boggle, visited, x, y, node->children[k], str + ch);
                }
            }
        }
    }

    visited[i][j] = false;
}

void solveBoggle(char boggle[M][N], Node* root){
    bool visited[M][N];
    memset(visited, false, sizeof(visited));

    Node* curr = root;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            int index = boggle[i][j]-'A';
            if(curr->children[index])
            {
                dfs(boggle, visited, i, j, curr->children[index], string(1,boggle[i][j]));
            }
        }
    }
}

int main(){
    string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GEE" };
    int n = sizeof(dictionary) / sizeof(dictionary[0]);

    Node* root = buildTrie(dictionary, n);

    char boggle[M][N] = {
        { 'G', 'I', 'Z' },
        { 'U', 'E', 'K' },
        { 'Q', 'S', 'E' }
    };

    solveBoggle(boggle, root);

    return 0;
}
