#include <bits/stdc++.h>

using namespace std;

class SimpleBankSystem
{
    int accountCount;
    vector<long long> accountBalance;
    
    bool IsValid(int account)
    {
        return (account > 0 and account <= accountCount);
    }

  public:
    SimpleBankSystem(vector<long long>& balance)
    {
        accountBalance = balance;
        accountCount = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        if(IsValid(account1) && IsValid(account2) && accountBalance[account1-1]>=money)
        {
            accountBalance[account1-1] -= money;
            accountBalance[account2-1] += money;
            return true;
        }
        return false;
	}

	bool deposit(int account, long long money)
	{
	    if(IsValid(account)){
	        accountBalance[account-1] += money;
	        return true;
	    }
	    return false;
	}

	bool withdraw(int account, long long money)
	{
	    if(IsValid(account) && accountBalance[account-1]>=money)
	    {
	        accountBalance[account-1] -= money;
	        return true;
	    }
	    return false;
	}
};

int main() {
    cout<<"Simple Bank System"<<endl;
    return 0;
}