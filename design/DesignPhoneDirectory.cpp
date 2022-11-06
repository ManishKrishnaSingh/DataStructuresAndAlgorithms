#include <bits/stdc++.h>

using namespace std;

class PhoneDirectory {
    unordered_set<int> directory;

  public:
    PhoneDirectory(int maxNumbers){
        for(int num=1; num<=maxNumbers; num++){
            directory.insert(num);
        }
    }

    int get(){
        int number = -1;
        if(!directory.empty()){
            number = *(directory.begin());
            directory.erase(number);
        }
        return number;
    }

    bool check(int number){
        return directory.count(number) > 0;
    }

    void release(int number){
        directory.insert(number);
    }
};

class PhoneDirectoryArray {
    int* next;
    int current;

  public :
    PhoneDirectoryArray(int maxNumbers){
        this->current = 0;

        next = new int[maxNumbers];
        for(int i=0; i<maxNumbers; ++i){
            next[i] = (i+1) % maxNumbers;
        }
    }

    int get(){
        int number = -1;
        if (next[current] != -1){
            number  = current;
            current = next[current];
            next[number] = -1;
        }
        return number;
    }

    bool check(int number){
        return next[number] != -1;
    }

    void release(int number){
        if (next[number] == -1){
            next[number] = current;
            current = number;
        }
    }
};

int main() {
    PhoneDirectory directory(12);

    directory.release(10);
    directory.release(15);

    cout << "#" << directory.get() << endl;
    cout << "#" << directory.get() << endl;

    cout << boolalpha << directory.check(10) << endl;
    cout << boolalpha << directory.check(16) << endl;

    return 0;
}