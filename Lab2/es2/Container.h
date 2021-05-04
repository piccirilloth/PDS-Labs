//
// Created by user on 07/04/2021.
//

#ifndef ES2_CONTAINER_H
#define ES2_CONTAINER_H
#include <iostream>

class Container {
    unsigned int _size;
    int *_vect;

public:
    Container();
    Container(int size);
    ~Container();
    Container &operator=(const Container &c);
    int size();
    void resize(int n);
    int& operator[](int i);
};
#endif //ES2_CONTAINER_H