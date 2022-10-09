#include <iostream>

using namespace std;

string ones[] = {
    "",
    "One ",
    "Two ",
    "Three ",
    "Four ",
    "Five ",
    "Six ",
    "Seven ",
    "Eight ",
    "Nine ",
    "Ten ",
    "Eleven ",
    "Twelve ",
    "Thirteen ",
    "Fourteen ",
    "Fifteen ",
    "Sixteen ",
    "Seventeen ",
    "Eighteen ",
    "Nineteen "
};

string tens[] = {
    "",
    "",
    "Twenty ",
    "Thirty ",
    "Forty ",
    "Fifty ",
    "Sixty ",
    "Seventy ",
    "Eighty ",
    "Ninety "
};

string numToWords(int number, string oStr){
    string str = "";
    if (number > 0 and number < 1000){
        if(number > 99){
            str += numToWords(((number/100)%10), "Hundred ");
            number = number%100; //try to get last 2 digits
        }

        if(number > 19){
            str += tens[number/10] + ones[number%10];
        } else {
            str += ones[number];
        }

        str += oStr;
    }
    return str;
}

string convertToWords(long number){
    string oStr="";

    oStr += numToWords((number/1000000000000)%1000, "Trillion ");
    oStr += numToWords((number/1000000000)%1000,    "Billion ");
    oStr += numToWords(((number/1000000)%1000),     "Million ");
    oStr += numToWords(((number/1000)%1000),        "Thousand ");
    oStr += numToWords(((number/100)%10),           "Hundred ");

    if (number > 100 && number%100){
        oStr += "and ";
    }

    oStr += numToWords((number%100), "");

    if(oStr == ""){
        oStr = "zero";
    }

    return oStr;
}

int main(){
	long int num = 246521167382378;

	string numStr = convertToWords(num);
	cout<<"["<<num<<"] : "<<numStr<<"\n";

	return 0;
}