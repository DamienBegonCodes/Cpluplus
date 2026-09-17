#include <mutex>
#include <condition_variable>
#include <iostream>
#include <syncstream>
#include <thread>
#include <queue>


int main()
{
    std::queue<int> q;
    std::mutex m;
    std::condition_variable cv;


    auto producer = [&q, &m, &cv] (int n)
    {
        std::osyncstream(std::cout) << "[Producer] created ! ID : " << std::this_thread::get_id() << std::endl;
        while(n > 0)
        {
            // Produces
            {
                std::lock_guard<std::mutex> l(m);
                int queue_elem = rand() % 100;
                q.push(queue_elem);
                std::osyncstream(std::cout) << "[Producer] Produced : " << queue_elem << std::endl;
            }
            cv.notify_one();

            int r = rand() % 5;
            std::this_thread::sleep_for(std::chrono::nanoseconds(r));
            
            --n;
        }
    };

    auto consumer = [&q, &m, &cv] ()
    {
        std::osyncstream(std::cout) << "[Consumer] created ! ID : " << std::this_thread::get_id() << std::endl;
        while(true)
        {
            // Consumes
            {
                std::unique_lock<std::mutex> l(m);
                cv.wait(l, [&q] () {return !q.empty();});
                int queue_elem = q.front();
                q.pop();
                std::osyncstream(std::cout) << "[Consumer] Consumed : " << queue_elem << std::endl;
                std::osyncstream(std::cout) << "[Consumer] Queue size : " << q.size() << std::endl;
            }
        }
    };

    int n = 100;

    std::thread t1(producer, n);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
