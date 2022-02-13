#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

using namespace std;

int counter=1;
std::mutex mtx;
std::condition_variable condition;

void printer(int reminder){
    std::unique_lock<std::mutex> uLock(mtx);
    while (counter < 10) {
        std::thread::id idThread = std::this_thread::get_id();
        condition.wait(uLock, [&reminder](){return counter%2==reminder;});
        std::cout<<"Thread ["<<idThread<<"] # Printing "<<counter++<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        condition.notify_all();
    }
}

int main(){
    std::thread oThread(printer, 1);
    std::thread eThread(printer, 0);

    oThread.join();
    eThread.join();

    return 0;
}

