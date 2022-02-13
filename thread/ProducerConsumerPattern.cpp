#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

std::mutex mtx;
std::queue<int> Topic;

class Consumer {
    string identifier;
  public:
    void operator() (string type){
        identifier = type;
        while (true) {
            // wait untill data is produced
            while (Topic.size() == 0) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

            // apply lock and consume topic data
            std::unique_lock<std::mutex> ul(mtx);
            consumeFromTopic();
            ul.unlock();
        }
    }

  private:
    void consumeFromTopic(){
        int data = Topic.front(); Topic.pop();
        cout<<"[C:"<<identifier<<"] :-> DATA = "<<data<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};

class Producer {
    string identifier;
  public:
    void operator()(string type){
        identifier = type;
        while (true) {
            // apply lock and produce topic data
            std::unique_lock<std::mutex> ul(mtx);
            produceToTopic();
            ul.unlock();

            // wait untill data is consumed
            while (Topic.size() > 0) {
                std::this_thread::sleep_for (std::chrono::seconds(1));
            }
        }
    }

  private:
    void produceToTopic(){
        int data = rand()%100; Topic.push(data);
        cout<<"[P:"<<identifier<<"] :-> DATA = "<<data<<endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
};

int main() {
    std::thread cThread(Consumer(), "Boeing");
    std::thread pThread(Producer(), "Indigo");

    cThread.join();
    pThread.join();

    return 0;
}

