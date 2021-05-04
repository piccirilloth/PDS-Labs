//
// Created by user on 30/03/2021.
//

#ifndef LAB1_DURATIONLOGGER_H
#define LAB1_DURATIONLOGGER_H
#include <iostream>
#include <ctime>

class DurationLogger {
    std::clock_t start;
    double duration;
    std::string name;
public:
    DurationLogger(const std::string& name);
    ~DurationLogger();
};


#endif //LAB1_DURATIONLOGGER_H
