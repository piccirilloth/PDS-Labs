//
// Created by picci on 04/06/2021.
//

#ifndef LAB5_JOBS_HPP
#define LAB5_JOBS_HPP
#include <queue>
#include <condition_variable>
#include <mutex>

template <typename T>
class Jobs {
private:
    std::queue<T> jobsQueue;
    std::condition_variable emptyCV;
    std::condition_variable fullCV;
    std::mutex queueLock;
    int threshold;
public:
    std::queue<std::string> fileJobs;
    std::mutex fileJobsMutex;
    std::mutex endMutex;
    int end;
    void put(T job) {
        std::unique_lock<std::mutex> ul(queueLock);
        if(jobsQueue.size() == threshold)
            fullCV.wait(ul);
        jobsQueue.push(job);
        if(jobsQueue.size() == 1)
            emptyCV.notify_one();
    }

    T get() {
        std::unique_lock<std::mutex> ul(queueLock);
        T ret;
        bool flag = false;
        while(jobsQueue.empty()) {
            {
                std::lock_guard<std::mutex> lg(endMutex);
                if (end == 10 && jobsQueue.empty())
                    flag = true;
            }
            if (flag) {
                ul.unlock();
                return ret;
            }
            emptyCV.wait(ul);
        }
        if(!jobsQueue.empty()) {
            ret = jobsQueue.front();
            jobsQueue.pop();
        }
        if(jobsQueue.size() == threshold-1)
            fullCV.notify_one();
        return ret;
    }

    void notifyAllConsumers() {
        emptyCV.notify_all();
    };

    Jobs(): threshold(10) {
        std::cout << "Construction of jobs\n";
    }
};

#endif //LAB5_JOBS_HPP
