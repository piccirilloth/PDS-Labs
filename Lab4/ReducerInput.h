//
// Created by picci on 08/05/2021.
//

#ifndef LAB4_REDUCERINPUT_H
#define LAB4_REDUCERINPUT_H
#include <iostream>
#include <string>


class ReducerInput {
    std::string key;
    int value;
    int acc;

public:
    ReducerInput(std::string key, int value, int acc);

    const std::string &getKey() const;

    void setKey(const std::string &key);

    int getValue() const;

    void setValue(int value);

    int getAcc() const;

    void setAcc(int acc);
};


#endif //LAB4_REDUCERINPUT_H
