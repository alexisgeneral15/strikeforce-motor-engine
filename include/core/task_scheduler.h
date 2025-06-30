#pragma once

#include <vector>
#include <functional>
#include <thread>
#include <mutex>
#include <queue>

class TaskScheduler {
public:
    TaskScheduler(size_t threadCount = std::thread::hardware_concurrency());
    ~TaskScheduler();
    
    template<typename Iterator, typename Func>
    void ParallelFor(Iterator begin, Iterator end, Func func);
    
    void WaitAll();

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop = false;
};