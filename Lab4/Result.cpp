//
// Created by oscar on 05/05/21.
//

#include "Result.h"

Result::Result(std::string key, int value): key(key), value(value) {

}

Result::Result(): key(""), value(0) {}

Result::~Result() {
    //std::cout << "calling destructor of Result\n";
}

const std::string &Result::getKey() const {
    return key;
}

void Result::setKey(const std::string &key) {
    Result::key = key;
}

int Result::getValue() const {
    return value;
}

void Result::setValue(int value) {
    Result::value = value;
}
