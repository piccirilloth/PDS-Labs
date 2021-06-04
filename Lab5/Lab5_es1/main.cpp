#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include "Jobs.hpp"
#include "Row.h"
#include <regex>
#include <thread>
#define N 10
#define M 10

namespace fs = std::filesystem;

std::mutex printMutex;

void producer(Jobs<Row> &j) {
    std::ifstream fin;
    char row[256];
    int count;
    fs::path p("C:\\Users\\picci\\OneDrive\\Desktop\\PDS-Labs\\Lab5\\es1");
    for(auto &file: fs::directory_iterator(p)) {
        //std::cout << "actual file " << file.path() << '\n';
        count = 0;
        fin.open(file.path());
        while(!fin.eof()) {
            count++;
            fin.getline(row, 256);
            std::string str(row);
            Row r(count, str, file.path().string());
            j.put(r);
        }
        fin.close();
    }
    // increment securely end variable
    std::lock_guard<std::mutex> lg(j.endMutex);
    j.end++;
    // notify all consumers
    j.notifyAllConsumers();
    std::lock_guard<std::mutex> lp(printMutex);
    std::cout << "end of the producer\n";
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
        if(std::regex_match(r.getRow(), std::regex("\\bciao\\b"))) {
            {
                std::lock_guard<std::mutex> lg(printMutex);
                std::cout << "matching found!" << ": " << r.getNRow() << " " << r.getFileName() << " " << r.getRow() << '\n';
            }
        }
    }
}

int main() {
    Jobs<Row> j;
    j.end = 0;
    std::vector<std::thread> consumers;
    std::thread prod(producer, std::ref(j));

    for(int i=0; i<N; i++)
        consumers.emplace_back(std::thread(consumer, std::ref(j)));

    prod.join();
    for(auto &t : consumers)
        t.join();
    return 0;
}
