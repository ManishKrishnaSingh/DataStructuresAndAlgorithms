#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

const int LL = 20;

vector<string> split(string iStr){
    vector<string> op;
    string word;
    stringstream ss(iStr);
    while(ss >> word){
        op.push_back(word);
    }
    return op;
}

string buildLeftJustifyLine(vector<string> words){
    string strLine = "";
    int n = words.size();
    if(n > 0) {
        strLine = words[0];
        for(int idx = 1; idx < n; idx++) {
            strLine = strLine + " " + words[idx++];
        }
    }
    return strLine;
}

string buildMiddleJustifyLine(vector<string> words){
    string strLine = "";

    int n = words.size();
    if(n > 0) {
        // add first word
        strLine = words[0];

        // count Total Extra Spaces
        int xtraSpaceTotal = LL - (n-1);
        for(auto word : words){
            xtraSpaceTotal -= word.length();
        }

        if(n == 1){
            //add spaces to the right
            while(xtraSpaceTotal > 0){
                xtraSpaceTotal--;
                strLine = strLine + " ";
            }
        } else {
            // fill extra spaces in between words
            int xtraSpacePerWord  = (xtraSpaceTotal/(n-1));
            int xtraSpaceLeftover = (xtraSpaceTotal%(n-1));

            int idx = 1;
            int xtraSpace;
            while(idx < n) {
                // apply leftover space
                if(xtraSpaceLeftover > 0){
                    xtraSpaceLeftover--;
                    strLine = strLine + " ";
                }

                // apply extra spaces
                xtraSpace = xtraSpacePerWord;
                while(xtraSpace > 0){
                    xtraSpace--;
                    strLine = strLine + " ";
                }

                // append space and the word
                strLine = strLine + " " + words[idx++];
            }
        }
    }

    return strLine;
}

void justifyTextPrint(int solution[], int idx, vector<string>& words){
    if (solution[idx] != 1) {
		justifyTextPrint(solution, solution[idx]-1, words);
    }

    // build and print line
    vector<string> wordsInLine;
    for(int i=solution[idx]-1; i<idx; i++){
        wordsInLine.push_back(words[i]);
    }

    // left justify if last line
    if(idx == words.size()){
        cout<<"["<<buildLeftJustifyLine(wordsInLine)<<"]\n";
    } else {
        cout<<"["<<buildMiddleJustifyLine(wordsInLine)<<"]\n";
    }
}

void justifyText(string iStr){
    if(!iStr.empty()){
        vector<string> words = split(iStr);

        int n = words.size();

        int strLength[n];
        for (int k = 0; k < n; k++) {
            strLength[k] = words[k].length();
        }

        // spaces[i][j] :->
        // extra spaces in line with words from i to j
        int spaces[n+1][n+1];
        for(int i=1; i<=n; i++){
            spaces[i][i] = LL - strLength[i-1];
            for(int j=i+1; j<=n; j++){
                spaces[i][j] = spaces[i][j-1] - strLength[j-1] - 1;
            }
        }

        // costmatrix[i][j] :->
        // line cost with words from i to j
        int costmatrix[n+1][n+1];
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                if (spaces[i][j] < 0){
                    costmatrix[i][j] = INF;
                } else if(j==n && spaces[i][j]>=0){
                    costmatrix[i][j] = 0;
                } else {
                    costmatrix[i][j] = pow(spaces[i][j], 3);
                }
            }
        }

        int solution[n+1]; // solution index
        int linecost[n+1]; // optimal cost of words from 1 to i

        linecost[0] = 0;
        for(int j=1; j<=n; j++){
            linecost[j] = INF;
            for(int i=1; i<=j; i++){
                if (linecost[i-1] != INF && costmatrix[i][j] != INF && (linecost[i-1] + costmatrix[i][j] < linecost[j]))
                {
                    linecost[j] = linecost[i-1] + costmatrix[i][j];
                    solution[j] = i;
                }
            }
        }

        // Now, print all justified lines
        justifyTextPrint(solution, n, words);
    }
}

int main(){
    string str = "Consanguineous. Science is what we understand well enough to explain to a computer. Art is everything else we do.";

    justifyText(str);

    return 0;
}
