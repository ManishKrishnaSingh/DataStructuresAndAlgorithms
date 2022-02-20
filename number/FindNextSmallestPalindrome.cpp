#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isAllNine(vector<int> v){
    for(int x: v){
        if(x != 9){
            return false;
        }
    }
    return true;
}

void nspUtil(vector<int>& v){
    int n = v.size();
    int mid = n/2;

    int i = mid-1;
    int j = (n%2)?mid+1:mid;

    while(i>=0 && j<n && v[i]==v[j]){
        i--; j++;
    }

    if(v[i] < v[j]){
        v[i] = v[i]+1;
    }

    while(i>=0 && j<n){
        v[j++] = v[i--];
    }
}

int nsp(int num){
    vector<int> v;

    while(num > 0){
        v.push_back(num%10);
        num = num/10;
    }

    reverse(v.begin(), v.end());

    if(isAllNine(v)){
        v[0] = 1;
        v.push_back(1);
        for(int i=1; i<v.size()-1; i++){
            v[i] = 0;
        }
    } else {
        nspUtil(v);
    }

    int result=0;
    for(int i=0; i<v.size(); i++){
        result = result*10 + v[i];
    }

    return result;
}

int main(){
    int number = 1235;
    cout<<"Next Smallest Palindrome = "<<nsp(number)<<endl;
    return 0;
}

