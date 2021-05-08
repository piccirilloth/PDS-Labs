//
// Created by picci on 08/05/2021.
//

#include "ReducerInput.h"

ReducerInput::ReducerInput(std::string key, int value, int acc): key(key), value(value), acc(acc) { }

const std::string &ReducerInput::getKey() const {
    return key;
}

void ReducerInput::setKey(const std::string &key) {
    ReducerInput::key = key;
}

int ReducerInput::getValue() const {
    return value;
}

void ReducerInput::setValue(int value) {
    ReducerInput::value = value;
}

int ReducerInput::getAcc() const {
    return acc;
}

void ReducerInput::setAcc(int acc) {
    ReducerInput::acc = acc;
}
