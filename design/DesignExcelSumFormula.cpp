#include <bits/stdc++.h>

using namespace std;

class Excel
{
    vector<vector<int>> sheet;
    unordered_map<int,unordered_map<int,vector<pair<int,int>>>> sums;

  public:
    Excel(int height, char width)
    {
        sheet.assign(height, vector<int>(width-'A'+1));
    }

    void set(int row, char col, int value)
    {
        removeReferences(row-1, col-'A');
        dfsUpdate(row-1, col-'A', value);
    }

    int get(int row, char col)
    {
        return sheet[row-1][col-'A'];
    }

    int sum(int row, char col, vector<string> numbers)
    {
        int rCell=row-1, cCell=col-'A', value=0;

        removeReferences(rCell, cCell);
        for(int i=0,r=0,c=0,n=numbers.size(); i<n; i++)
        {
            auto str = numbers[i];
            auto pos = str.find(':');
            if(pos == string::npos)
            {
                r = stoi(str.substr(1)) - 1;
                c = str[0] - 'A';
                value += sheet[r][c];
                sums[r][c].push_back({rCell, cCell});
            }
            else
            {
                for(r=stoi(str.substr(1,pos-1)) - 1; r<=stoi(str.substr(pos+2)) - 1; r++)
                {
                    for(c=str[0]-'A'; c<=str[pos+1] - 'A'; c++)
                    {
                        value += sheet[r][c];
                        sums[r][c].push_back({rCell, cCell});
                    }
                }
            }
        }
        dfsUpdate(rCell, cCell, value);
        return value;
    }

    void removeReferences(int row, int col)
    {
        for(auto rIter=sums.begin(); rIter!=sums.end(); rIter++)
        {
            for(auto cIter=rIter->second.begin(); cIter!=rIter->second.end(); cIter++)
            {
                auto& cells = cIter->second;
                for (auto& cell : cells)
                {
                    if(cell.first==row && cell.second==col)
                    {
                        cells.erase(find(cells.begin(), cells.end(),make_pair(row,col)));
                    }
                }
            }
        }
    }

    void dfsUpdate(int row, int col, int value)
    {
        int diff = value - sheet[row][col];

        sheet[row][col] = value;
        if(sums.count(row) && sums[row].count(col))
        {
            int rCell, cCell;
            for(auto& cell : sums[row][col])
            {
                rCell = cell.first; cCell = cell.second;
                dfsUpdate(rCell, cCell, sheet[rCell][cCell]+diff);
            }
        }
    }
};

int main()
{
    cout << "Excel Sum Formula";

    Excel* xls = new Excel(3,'C');

    xls->set(1, 'A', 2);
    cout<<"\nExcel CELL = "<<xls->get(1, 'A'); // 2
    cout<<"\nExcel##SUM = "<<xls->sum(3, 'C', {"A1", "A1:B2"}); // 4

    xls->set(2, 'B', 2);
    cout<<"\nExcel CELL = "<<xls->get(3, 'C'); // 6

    return 0;
}