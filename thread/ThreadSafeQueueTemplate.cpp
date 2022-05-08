#include <bits/stdc++.h>

using namespace std;

template<typename T>
class ThreadSafeQueue {
    std::queue<T> _queue;

  private:
    std::mutex _mutex;
    std::condition_variable _cond;

  public:
    T pop() {
        cout << "ThreadSafeQueue::pop" << endl;
        std::unique_lock<std::mutex> mlock(_mutex);

        while (_queue.empty()) {
            _cond.wait(mlock);
        }

        T item = _queue.front();
        _queue.pop();

        return item;
    }

    void push(const T& item) {
        cout << "ThreadSafeQueue::push(copy)" << endl;
        std::unique_lock<std::mutex> mlock(_mutex);
        _queue.push(item);
        mlock.unlock();
        _cond.notify_one();
    }

    void push(T&& item) {
        cout << "ThreadSafeQueue::push(move)" << endl;
        std::unique_lock<std::mutex> mlock(_mutex);
        _queue.push(std::move(item));
        mlock.unlock();
        _cond.notify_one();
    }
};

int main() {
    ThreadSafeQueue<int> aThreadSafeQueue;

    int x = 0; // copy
    aThreadSafeQueue.push(x);

    // calls push with move
    aThreadSafeQueue.push(1);
    aThreadSafeQueue.push(2);
    aThreadSafeQueue.push(3);
    aThreadSafeQueue.push(4);
    aThreadSafeQueue.push(5);

    return 0;
}


