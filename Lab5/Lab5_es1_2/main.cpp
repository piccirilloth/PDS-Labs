#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include "Jobs.hpp"
#include "Row.h"
#include <regex>
#include <thread>
#include <queue>
#define N 10
#define M 10

namespace fs = std::filesystem;

std::mutex printMutex;

void producer(Jobs<Row> &j) {
    bool flag = false;
    std::ifstream fin;
    std::string fn;
    char row[256];
    int count;
    while(!flag) {
        fn = "";
        {
            std::lock_guard<std::mutex> lg(j.fileJobsMutex);
            if(j.fileJobs.size() == 0) {
                flag = true;
                continue;
            }
        }
        {
            std::lock_guard<std::mutex> lg(j.fileJobsMutex);
            if(!j.fileJobs.empty()) {
                fn = j.fileJobs.front();
                j.fileJobs.pop();
            }
        }
        if(!fn._Equal("")) {
            fin.open(fn);
            count = 0;
            while(!fin.eof()) {
                count++;
                fin.getline(row, 256);
                std::string str(row);
                Row r(count, str, fn);
                j.put(r);
            }
            fin.close();
        }
    }
    {
        std::lock_guard<std::mutex> lg(j.endMutex);
        j.end++;
        // notify all consumers
        //if (j.end == M)
            //j.notifyAllConsumers();
    }
    std::lock_guard<std::mutex> lp(printMutex);
    std::cout << "end of a producer\n";
}

void consumer(Jobs<Row> &j) {
    bool flag = false;
    while(!flag) {
         Row r = j.get();
         if(r.getNRow() == -1) {
            std::lock_guard<std::mutex> lg(printMutex);
            std::cout << "end of a consumer\n";
            flag = true;
         }
        else if(std::regex_match(r.getRow(), std::regex("\\bciao\\b"))) {
            {
                std::lock_guard<std::mutex> lg(printMutex);
                std::cout << "matching found!" << ": " << r.getNRow() << " " << r.getFileName() << " " << r.getRow() << '\n';
            }
        }
    }
}

void mainThread(Jobs<Row> &j) {
    fs::path p(R"(C:\Users\picci\OneDrive\Desktop\PDS-Labs\Lab5\Lab5_es1_2\es1)");
    for(auto &file: fs::directory_iterator(p)) {
        j.fileJobs.push(file.path().string());
    }
}

int main() {
    Jobs<Row> j;
    j.end = 0;

    // main thread puts file name into fileJobs
    mainThread(j);

    std::vector<std::thread> consumers;
    std::vector<std::thread> producers;

    for(int i=0; i<M; i++)
        producers.emplace_back(std::thread(producer, std::ref(j)));
    for(int i=0; i<N; i++)
        consumers.emplace_back(std::thread(consumer, std::ref(j)));

    for(auto &t : producers)
        t.join();
    for(auto &t : consumers)
        t.join();
    /*std::queue<int> q;
    q.push(1);
    q.push(2);
    q.front();
    q.pop();
    q.front();

    q.pop();
    if(q.size() == 0)
        std::cout << "ciao";*/
    return 0;
}
