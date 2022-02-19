#include <bits/stdc++.h>

using namespace std;

int findMaximumOverlap(string str1, string str2, string& oStr){
    int overlap = INT_MIN;

    int m = str1.length();
    int n = str2.length();
    for(int l=0; l<min(m, n); l++){
        if(str1.substr(0,l).compare(str2.substr(n-l)) == 0){
            if(l>overlap){
                overlap = l;
                oStr = str2 + str1.substr(l);
            }
        }
        if(str1.substr(m-l).compare(str2.substr(0,l)) == 0){
            if(l>overlap){
                overlap = l;
                oStr = str1 + str2.substr(l);
            }
        }
    }
    return overlap;
}

string findShortestCommonSuperString(string input[], int n){
    if(n==1){
        return input[0];
    }

    string str = "";
    int left,right;
    int maxoverlap = INT_MIN;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int overlap = findMaximumOverlap(input[i], input[j], str);
            if(overlap>maxoverlap){
                left = i; right = j;
                maxoverlap = overlap;
            }
        }
    }
    if(maxoverlap == 0){
        input[0] += input[n-1];
    } else {
        input[left] = str;
        input[right] = input[n-1];
    }
    return findShortestCommonSuperString(input, n-1);
}

int main(){
    string arr[] = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"};
    int n = sizeof(arr)/sizeof(arr[0]);

    string str = findShortestCommonSuperString(arr,n);
    cout<<"Shortest Common Super String = "<<str<<endl;

    return 0;
}

