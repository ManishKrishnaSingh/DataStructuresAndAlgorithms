#include <iostream>

using namespace std;

void permute(string str, int left, int right){
    if(left==right){
        cout<<str<<endl;
    } else {
        for (int i=left; i<=right; i++){
            swap(str[left], str[i]);
            permute(str, left+1, right);
            swap(str[left], str[i]);
        }
    }
}

int main(){
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}

