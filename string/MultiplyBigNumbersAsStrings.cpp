#include <cstring>
#include <iostream>

using namespace std;

string multiply(string num1, string num2){
    int m = num1.length();
    int n = num2.length();

    int multi[m+n];
    memset(multi, 0, sizeof(multi));

    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int val = (num1[i]-'0') * (num2[j]-'0');
            int sum = multi[i+j+1] + val;

            multi[i+j] += sum/10;
            multi[i+j+1] = sum%10;
        }
    }

    string result = "";
    for(int val : multi){
        if(result.length()!=0 || val!=0){
            result = result + to_string(val);
        }
    }

    return result;
}

int main(){
    string num1 = "1235421415454545454545454544";
    string num2 = "1714546546546545454544548544544545";

    cout<<"Multiplicattion = "<<multiply(num1, num2)<<endl;

    return 0;
}

