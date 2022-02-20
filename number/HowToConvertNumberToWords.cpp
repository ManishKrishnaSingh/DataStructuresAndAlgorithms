#include <iostream>

using namespace std;

string ones[] = {"",
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

string tens[] = {"", "",
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
    if(number > 19){
        str += tens[number/10] + ones[number%10];
    } else {
        str += ones[number];
    }
    if (number > 0){
        str += oStr;
    }
    return str;
}

string convertToWords(long number){
    string oStr="";

    oStr += numToWords((number/10000000),     "Crore ");
    oStr += numToWords(((number/100000)%100), "Lakh ");
    oStr += numToWords(((number/1000)%100),   "Thousand ");
    oStr += numToWords(((number/100)%10),     "Hundred ");

    if (number > 100 && number%100){
        oStr += "and ";
    }
    oStr += numToWords((number%100), "");
    if(oStr==""){
        oStr = "zero";
    }
    return oStr;
}

int main(){
	long num=673823;//long handles 9 digits
	string numStr = convertToWords(num);
	cout<<"["<<num<<"] = "<<numStr<< endl;
	return 0;
}

