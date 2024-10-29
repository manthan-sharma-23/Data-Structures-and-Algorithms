#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

class Latch
{
public:
    explicit Latch(int count) : count(count) {}

    // Decrements the latch counter
    void count_down()
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (--count == 0)
        {
            cv.notify_all(); // Notify all threads if count reaches zero
        }
    }

    // Waits until the latch count reaches zero
    void wait()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]()
                { return count == 0; });
    }

private:
    int count;
    std::mutex mtx;
    std::condition_variable cv;
};

int main()
{
    const int numThreads = 5;
    Latch latch(numThreads); // Custom latch with a count equal to the number of threads

    auto worker = [&](int id)
    {
        std::cout << "Thread " << id << " is ready.\n";
        latch.count_down(); // Decrement the latch count
        latch.wait();       // Wait until the latch count reaches zero
        std::cout << "Thread " << id << " is proceeding.\n";
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i)
    {

        threads.emplace_back(worker, i + 1);
    }

    for (auto &t : threads)
    {
        t.join();
    }
    return 0;
}
