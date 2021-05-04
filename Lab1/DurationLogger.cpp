//
// Created by user on 30/03/2021.
//

#include "DurationLogger.h"
DurationLogger::DurationLogger(const std::string &name) {
    this->start = std::clock();
    this->name = name;
    this->duration = 0;
    std::cout << ">>>>>>>>>>>>>> starting [ " << name << " ]\n";
}

DurationLogger::~DurationLogger() {
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "<<<<<<<<<<<<<< ending [ " << name << " ]: [ " << duration << " ] sec\n";
}