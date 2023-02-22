#include "ThreadPool.hpp"

ThreadPool::ThreadPool(size_t nThreads) : threads_{}, tasks_{}, tasks_mutex_{}, activity{}, inactive{}, end{false}, actives{0} {
  auto consumer = [this] () {
    std::unique_lock<std::mutex> lock(tasks_mutex_);
    while(true)
    {
      if (!tasks_.empty())
      {
        std::function<void()> task = tasks_.front();
        tasks_.pop();
        ++actives;
        lock.unlock();
        task();
        lock.lock();
        --actives;
        if 
      }
    }

  }

  for (size_t i = 0; i < nThreads; ++i)
    threads_.push_back(std::thread{});

}

ThreadPool::~ThreadPool() {
  join();
}

void ThreadPool::join() {
  for (std::thread &th : threads_)
    if (th.joinable())
      th.join();
}	
