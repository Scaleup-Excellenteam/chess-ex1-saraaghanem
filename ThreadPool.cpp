#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back([this]() {
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    this->condition.wait(lock, [this]() {
                        return this->stop || !this->tasks.empty();
                    });
                    if (this->stop && this->tasks.empty())
                        return;
                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                }
                task();
            }
        });
    }
}

void ThreadPool::enqueue(const std::function<void()>& task) {
    {
        std::lock_guard<std::mutex> lock(queue_mutex);
        if (stop) return;
        tasks.push(task);
    }
    condition.notify_one();
}

void ThreadPool::shutdown() {
    stop = true;
    condition.notify_all();
    for (std::thread& worker : workers) {
        if (worker.joinable())
            worker.join();
    }
}

ThreadPool::~ThreadPool() {
    shutdown();
}
