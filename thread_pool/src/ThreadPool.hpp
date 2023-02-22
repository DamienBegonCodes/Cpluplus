#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <list>
#include <deque>
#include <queue>

class ThreadPool {

private:
  std::queue<std::function<void()>> tasks_;
  std::list<std::thread> threads_;
  std::mutex tasks_mutex_;
  std::condition_variable activity;
  std::condition_variable inactive;
  bool end;
  unsigned int actives;
public:

  // Constructor of a pool with a given number of threads
  ThreadPool(size_t nThreads);

  // Destructor to remove ressources
  ~ThreadPool();

  // Method template to post any callable with its arguments
  template<typename Func, typename... Args>
  ThreadPool& operator() (const Func& func, Args... args) {
    {
      std::lock_guard<std::mutex> lock(tasks_mutex_);
      tasks_.push(func, args...);
    }
    activity.notify_one();
    return *this;
  }

  // Method to join all threads of the pool
  void join();
};
