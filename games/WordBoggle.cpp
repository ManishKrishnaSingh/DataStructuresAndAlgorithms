#include <bits/stdc++.h>

using namespace std;

#define M 3
#define N 3

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

void insert(Node* node, char* word){
    int n = strlen(word);
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

Node* buildTrie(char* dictionary[], int n){
    Node* root = new Node();
    for(int i=0; i<n; i++){
        insert(root, dictionary[i]);
    }
    return root;
}

bool isSafe(bool visited[M][N], int i, int j){
    return (!visited[i][j] && i<M && i>=0 && j<N && j>=0);
}

void findWords(char boggle[M][N], bool visited[M][N], int i, int j, Node* node, string str){
    if(node->isLeaf){
        std::cout << str << std::endl;
    }

    if(isSafe(visited, i, j)){
        visited[i][j] = true;
        for(int k=0; k<26; k++){
            if(node->children[k]!=nullptr){
                char ch = (char)('A' + k);
                str = str + ch;
                if(isSafe(visited,i+1, j) && boggle[i+1][j]==ch){
                    findWords(boggle, visited, i+1, j, node->children[k], str);
                }
                if(isSafe(visited,i-1, j) && boggle[i-1][j]==ch){
                    findWords(boggle, visited, i-1, j, node->children[k], str);
                }
                if(isSafe(visited,i, j+1) && boggle[i][j+1]==ch){
                    findWords(boggle, visited, i, j+1, node->children[k], str);
                }
                if(isSafe(visited,i, j-1) && boggle[i][j-1]==ch){
                    findWords(boggle, visited, i, j-1, node->children[k], str);
                }
                if(isSafe(visited,i+1, j+1) && boggle[i+1][j+1]==ch){
                    findWords(boggle, visited, i+1, j+1, node->children[k], str);
                }
                if(isSafe(visited,i-1, j-1) && boggle[i-1][j-1]==ch){
                    findWords(boggle, visited, i-1, j-1, node->children[k], str);
                }
                if(isSafe(visited,i+1, j-1) && boggle[i+1][j-1]==ch){
                    findWords(boggle, visited, i+1, j-1, node->children[k], str);
                }
                if(isSafe(visited,i-1, j+1) && boggle[i-1][j+1]==ch){
                    findWords(boggle, visited, i-1, j+1, node->children[k], str);
                }
            }
        }
        visited[i][j] = false;
    }
}

void solveBoggle(char boggle[M][N], Node* root){
    bool visited[M][N];
    memset(visited, false, sizeof(visited));

    string str = "";
    Node* pCrawl = root;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            int index=boggle[i][j]-'A';
            if(pCrawl->children[index]){
                str = str + boggle[i][j];
                findWords(boggle, visited, i, j, pCrawl->children[index], str);
                str = "";
            }
        }
    }
}

int main(){
    char* dictionary[] = { "GEEKS", "FOR", "QUIZ", "GEE" };
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

