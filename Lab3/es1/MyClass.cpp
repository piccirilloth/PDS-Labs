//
// Created by user on 21/04/2021.
//

#include "MyClass.h"

MyClass::MyClass() {
    value = -1;
}
MyClass::MyClass(int v) : value(v) {}

int MyClass::getValue() const{
    return value;
}