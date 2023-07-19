#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> directions =
{
    {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}
};

bool IsSafe(int& x, int& y, int& ROW, int& COL)
{
    if(x >= 0 and x < ROW and y >= 0 and y < COL)
    {
        return true;
    }
    return false;
}

bool dfs(vector<vector<char>>&board, int& i, int& j, int& ROW, int& COL, vector<vector<bool>>& visited, string& word, int index)
{
    visited[i][j] = true;

    if(index == word.size())
    {
        return true;
    }

    int x, y;
    for(auto& direction : directions)
    {
        x = i + direction.first;
        y = j + direction.second;
        if(IsSafe(x,y,ROW,COL) and !visited[x][y] and index < word.size() and board[x][y] == word[index])
        {
            return dfs(board, x, y, ROW, COL, visited, word, index+1);
        }
    }

    return false;
}

void searchWordsInCharacterGrid(vector<vector<char>>& board, vector<string>& words)
{
    if(board.size()==0 || board[0].size()==0 || words.size()==0)
    {
        return;
    }

    int ROW = board.size();
    int COL = board[0].size();

    vector<vector<bool>> visited(ROW,vector<bool>(COL, false));

    int i, j;
    for(auto& word : words)
    {
        visited.assign(ROW,vector<bool>(COL, false));

        for(i = 0; i < ROW; i++)
        {
            for(j = 0; j < COL; j++)
            {
                if(word[0] == board[i][j] and !visited[i][j])
                {
                    if(dfs(board, i, j, ROW, COL, visited, word, 1))
                    {
                        cout<<word<<" found at "<<i<<","<<j<<endl;
                        visited.assign(ROW,vector<bool>(COL, false));
                    }
                }
            }
        }
    }
}

int main()
{
    vector<vector<char>> board =
    {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words =
    {
        "oath", "pea", "eat", "rain"
    };

    searchWordsInCharacterGrid(board, words);

    return 0;
}
