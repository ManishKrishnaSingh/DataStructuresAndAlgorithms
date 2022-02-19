#include <climits>
#include <iostream>

using namespace std;

bool isPalindrome(string str, int low, int high){
    while(low<high){
        if(str[low]!=str[high]){
            return false;
        }
        low++; high--;
    }
    return true;
}

int minCutsPalindrome(string str, int low, int high){
    if(low>high || isPalindrome(str, low, high)){
        return 0;
    }

    int nCuts, minCuts=INT_MAX;
    for(int k=low; k<high; k++){
        nCuts = 1 + minCutsPalindrome(str,low,k) + minCutsPalindrome(str,k+1,high);
        minCuts = min(minCuts, nCuts);
    }
    return minCuts;
}

int main() {
    string str = "ababbbabbababa";

    int nCuts = minCutsPalindrome(str, 0, str.length()-1);
    cout << "Minimum Cuts[Palindrome Partitioning]="<<nCuts<<endl;

    return 0;
}

