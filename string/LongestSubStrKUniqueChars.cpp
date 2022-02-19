#include <iostream>

using namespace std;

int maxLengthKUniqueChars(string str, int K){
    int maxLength = -1;
    int n = str.length();

    int count = 0;
    int start = 0;
    int hash[256] = {0};
    for(int i=0; i<n; i++){
        if(hash[str[i]] == 0){
            count++;
        }
        hash[str[i]]++;

        if(count == K){
            maxLength = max(maxLength, i-start+1);

            if((i+1)<n && hash[str[i+1]] == 0){
                while(count == K){
                    hash[str[start]]--;
                    if(hash[str[start]]==0){
                        count--;
                    }
                    start++;
                }
            }
        }
    }

    return maxLength;
}

int main(){
    int K = 3;
    string str = "aabacbebebe";

    int result = maxLengthKUniqueChars(str, K);
    cout<<"Max Length K-Unique Chars = "<<result<<endl;

    return 0;
}

