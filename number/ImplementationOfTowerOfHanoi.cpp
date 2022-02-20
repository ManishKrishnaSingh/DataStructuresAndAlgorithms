#include <iostream>

using namespace std;

void solveTOH(int disks, char F, char T, char X){
    if(disks > 0){
        solveTOH(disks-1, F, X, T);
        cout<<"Move disk ["<<disks<<"] "<<F<<" => "<<T<<endl;
        solveTOH(disks-1, X, T, F);
    }
}

int main(){
    int disks = 4;
    solveTOH(disks, 'A', 'C', 'B');

    return 0;
}

