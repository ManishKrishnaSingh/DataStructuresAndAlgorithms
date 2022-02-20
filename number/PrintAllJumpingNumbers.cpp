#include <bits/stdc++.h>

using namespace std;

void PrintJumpingNumbers(int N){
    vector<int> result;
    result.push_back(0);

    queue<int> q;
    for(int i=1; i<=9; i++){
        q.push(i);
    }

    while(!q.empty()){
        int num=q.front(); q.pop();
        if(result.size() < N){
            result.push_back(num);
        } else {
            break;
        }

        int lastdigit = num%10;
        if(lastdigit == 0){
            q.push(num*10 + lastdigit+1);
        } else if(lastdigit == 9){
            q.push(num*10 + lastdigit-1);
        } else {
            q.push(num*10 + lastdigit-1);
            q.push(num*10 + lastdigit+1);
        }
    }

    cout<<"Jumping Numbers:";
    for(int i=0; i<result.size(); i++){
        cout<<" "<<result[i];
    }
}

int main(){
    int N = 10;
    PrintJumpingNumbers(N);
    return 0;
}

