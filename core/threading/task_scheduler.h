#pragma once
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

class Task {
public:
    virtual void execute() = 0;
    virtual ~Task() = default;
};

class TaskScheduler {
public:
    TaskScheduler(size_t num_threads);
    ~TaskScheduler();
    
    void schedule(Task* task);
    
private:
    std::vector<std::thread> workers;
    std::queue<Task*> task_queue;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool running = true;
};