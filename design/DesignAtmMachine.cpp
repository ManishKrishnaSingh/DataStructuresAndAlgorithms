#include <bits/stdc++.h>

using namespace std;

class AutomatedTellerMachine {
    vector<int> noteValue; // stores note denomination value
    vector<int> noteCount; // stores note denomination count

  public:
    AutomatedTellerMachine() {
        noteValue = {20, 50, 100, 200, 500};
        noteCount = {0, 0, 0, 0, 0};
    }

    void deposit(vector<int> iNoteCount) {
        for(int i=0; i<5; i++){
            noteCount[i] += iNoteCount[i];
        }
    }

    vector<int> withdraw(int amountToWithdraw) {
        vector<int> noteWithdrawn(5,0);
        vector<int> tempCount = noteCount;

        bool IsPossibleToWithdraw = false;
        for(int i=4; i>=0; i--){
            // start from the highest note value
            int notes = amountToWithdraw/noteValue[i];

            // only available notes
            if(notes > noteCount[i]){
                notes = noteCount[i];
            }

            // decrease note count
            noteCount[i]     -= notes;
            
            // update withdrwan notes
            noteWithdrawn[i]  = notes;
            // update remaining amount to withdraw
            amountToWithdraw -=  notes*noteValue[i];

            if(amountToWithdraw == 0){
                IsPossibleToWithdraw = true;
                break; // no need to check
            }
        }

        // restores older count
        if(!IsPossibleToWithdraw){ 
            noteCount = tempCount;
            noteWithdrawn[0] = -1;
            noteWithdrawn.resize(1);
        }

        return noteWithdrawn;
    }
};

int main(){
    AutomatedTellerMachine atm;

    atm.deposit({0,0,1,2,1});
    
    cout<<"atm withdrawn notes:";
    for(auto note : atm.withdraw(600))
    {
        cout << " " << note;
    }

    return 0;
}