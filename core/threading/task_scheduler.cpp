#include "task_scheduler.h"

void TaskScheduler::initialize() {
    workers.reserve(thread_count);
    for (size_t i = 0; i < thread_count; ++i) {
        workers.emplace_back([this] {
            while (running) {
                Task* task = nullptr;
                {
                    std::unique_lock lock(queue_mutex);
                    condition.wait(lock, [this] { 
                        return !task_queue.empty() || !running; 
                    });
                    
                    if (!running) break;
                    
                    task = task_queue.front();
                    task_queue.pop();
                }
                task->execute();
            }
        });
    }
}