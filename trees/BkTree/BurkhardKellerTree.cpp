#include <vector>
#include <iostream>

using namespace std;

#define TOL 2
#define LEN 10

int min(int x, int y, int z){
    return min(x, min(y, z));
}

int editDistance(string str1, string str2){
    int m = str1.length();
    int n = str2.length();

    int dp[m+1][n+1];

    // base cases
    for(int i=0; i<=m; i++){
        dp[i][0] = i;
    }
    for(int j=0; j<=n; j++){
        dp[0][j] = j;
    }

    // populating matrix
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
	    } else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
	    }
        }
    }
    return dp[m][n];
}

typedef struct node {
    string word;
    node *next[LEN];
    node(string str){
        this->word = str;
        for(int i=0; i<LEN; i++){
            this->next[i] = nullptr;
        }
    }
}TreeNode;

class BurkhardKellerTree{
  private:
    TreeNode* root;
  public:
    BurkhardKellerTree(){
        root = nullptr;
    }

    void addNode(string word){
        root = addNode(root, word);
    }

    TreeNode* addNode(TreeNode* node, string word){
        if (node == nullptr){
            node =  new TreeNode(word);
        } else {
            int dist = editDistance(node->word, word);
            node->next[dist] = addNode(node->next[dist], word);
        }
        return node;
    }

    void findSimilarWords(string word){
        cout<<"Hint ["<<word<<"]:"<<endl;
        vector<string> result = findSimilarWords(root, word);
        for(int i=0; i<result.size(); i++){
            cout<<"["<<i<<"] => "<<result[i]<<endl;
        }
        cout<<endl;
    }

    vector<string> findSimilarWords(TreeNode* node, string word){
        vector<string> result;
        if (node != nullptr){
            int dist = editDistance(node->word, word);
            if (dist <= TOL){
                result.push_back(node->word);
            }

            for(int i=0; i<LEN; i++){
                if(node->next[i] != nullptr){
                    vector<string> tmp = findSimilarWords(node->next[i], word);
                    for (auto i : tmp){
                        result.push_back(i);
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    string dictionary[] = {"hell","help","shell","smell","fell","felt","oops","pop","oouch","halt"};
    int n = sizeof(dictionary)/sizeof(string);

    BurkhardKellerTree *bkTree = new BurkhardKellerTree();
    for(int i=0; i<n; i++){
        bkTree->addNode(dictionary[i]);
    }

    bkTree->findSimilarWords("ops");
    bkTree->findSimilarWords("helt");

    return 0;
}

