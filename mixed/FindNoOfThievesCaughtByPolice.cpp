/************************************************************************************
Given an array of size n that has the following specifications:
- Each element in the array contains either a policeman or a thief.
- Each policeman can catch only one thief.
- A policeman cannot catch a thief who is more than K units away from the policeman.
************************************************************************************/
#include <vector>
#include <iostream>

using namespace std;

int findThievesCaughtByPolice(char arr[], int n, int policeRange){
    vector<int> police;
    vector<int> thieves;

    for(int i=0; i<n; i++){
        if(arr[i] == 'P'){
            police.push_back(i);
        } else {
            thieves.push_back(i);
        }
    }

    int nThieves = 0;

    int idxPolice=0, idxThieve=0;
    while(idxPolice < police.size() && idxThieve < thieves.size()){
        if(abs(police[idxPolice]-thieves[idxThieve]) <= policeRange){
            nThieves++;
            idxThieve++;
            idxPolice++;
        } else if(police[idxPolice] < thieves[idxThieve]){
            idxPolice++;
        } else {
            idxThieve++;
        }
    }

    return nThieves;
}

int main(){
    char arr[]={'P','T','T','P','T'};
    int n = sizeof(arr)/sizeof(char);

    int nThieves = findThievesCaughtByPolice(arr, n, 2);
    cout << "Maximum thieves caught = "<<nThieves<<endl;

    return 0;
}

