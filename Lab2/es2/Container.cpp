//
// Created by user on 07/04/2021.
//

#include "Container.h"

Container::Container() : _size(0) {
    std::cout << "Calling default constructor\n";
    _vect = nullptr;
}

Container::Container(int size) : _size(size) {
    std::cout << "calling _size constructor\n";
    _vect = new (std::nothrow) int[size];
    if(_vect == nullptr)
        std::cout << "Error in allocating vect\n";
}

Container::~Container() {
    std::cout << "Calling container destructor\n";
    if(_vect != nullptr)
    {
        delete[] _vect;
        _vect = nullptr;
    }
}

Container & Container::operator=(const Container &c) {
    std::cout << "Copy operator\n";
    if(&c != this)
    {
        this->_size = c._size;
        delete[] this->_vect;
        _vect = nullptr;
        _vect = new (std::nothrow) int[this->_size];
        if(_vect == nullptr)
            std::cout << "Error in allocating vect\n";
        else
            std::memcpy(this->_vect, c._vect, this->_size);
    }
    return *this;
}

int Container::size() {
    return _size;
}

void Container::resize(int n) {
    if(_vect != nullptr)
    {
        int *temp = new (std::nothrow) int[_size];
        if(temp == nullptr)
            std::cout << "Error in allocating temp vector\n";
        else
        {
            std::memcpy(temp, _vect, _size);
            delete[] _vect;
            _vect = nullptr;
            _vect = new (std::nothrow) int[n];
            if(_vect == nullptr)
                std::cout << "error in allocating vect\n";
            else
                std::memcpy(_vect, temp, _size);
            delete[] temp;
            temp = nullptr;
            _size = n;
        }
    }
    else
    {
        _vect = new (std::nothrow) int[n];
        if(_vect == nullptr)
            std::cout << "error in allocating vect\n";
        _size = n;
    }
}

int& Container::operator[](int i) {
    if(i < _size)
        return _vect[i];
    else
    {
        std::cout << "invalid index\n";
        exit(0);
    }
}