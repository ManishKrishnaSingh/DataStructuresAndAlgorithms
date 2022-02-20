#include <iostream>

using namespace std;

typedef struct dob{
    int dd, mm, yr;
    dob(int dd, int mm, int yr){
        this->dd = dd;
        this->mm = mm;
        this->yr = yr;
    }
}DateOfBirth;

void findDifference(DateOfBirth x, DateOfBirth y){
    int diffYR = x.yr - y.yr;
    int diffMM = x.mm - y.mm;
    int diffDD = x.dd - y.dd;

    if(diffDD < 0){
        diffDD += 30;
        diffMM -= 1;
    }
    if(diffMM < 0){
        diffMM += 12;
        diffYR -= 1;
    }

    cout<<diffYR<<" years, "<<diffMM<<" months and "<<diffDD<<" days"<<endl;
}

int main(){
    DateOfBirth now(04, 01, 2021);
    DateOfBirth dob(16, 12, 2009);

    findDifference(now, dob);

    return 0;
}

