//
// Created by oscar on 05/05/21.
//

#ifndef LAB4_RESULT_H
#define LAB4_RESULT_H
#include <iostream>

class Result {
private:
    std::string key;
    int value;

public:
    Result(std::string key, int value);
    Result();
    ~Result();

    const std::string &getKey() const;

    void setKey(const std::string &key);

    int getValue() const;

    void setValue(int value);
};


#endif //LAB4_RESULT_H
