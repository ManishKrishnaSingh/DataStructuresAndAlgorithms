#include <bits/stdc++.h>

using namespace std;

class StructuredQueryLanguage
{
    // hash map of table name to curr row id
    unordered_map<string, int> mTableToRowId;
    // hash map of table name to hash map of row id and row data
    unordered_map<string, unordered_map<int, vector<string>>> sql;

  public:
    StructuredQueryLanguage(vector<string> iTableNames, vector<int> iNoOfColumns)
    {
        for (auto& aTableName : iTableNames)
        {
            this->mTableToRowId[aTableName] = 0;
        }
    }

    void insertRow(string iTableName, vector<string> iRow)
    {
        this->mTableToRowId[iTableName] += 1;
        this->sql[iTableName][mTableToRowId[iTableName]] = iRow;
    }

    void deleteRow(string iTableName, int iRowId)
    {
        this->sql[iTableName].erase(iRowId);
    }

    string selectCell(string iTableName, int iRowId, int iColumnId)
    {
        return this->sql[iTableName][iRowId][iColumnId-1];
    }
};

int main()
{
    cout<<"Structured Query Language"<<endl;

    StructuredQueryLanguage sql(
        {"Employee", "Department"}, {2, 2}
    );

    sql.insertRow("Employee", {"Krishna", "India"});
    sql.insertRow("Employee", {"Michael", "France"});

    sql.deleteRow("Employee", 1);

    string str = sql.selectCell("Employee", 2, 2);
    cout << "Employee Country:[" << str << "]" << endl;

    return 0;
}