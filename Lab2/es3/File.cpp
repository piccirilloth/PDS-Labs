//
// Created by user on 19/04/2021.
//

#include "File.h"

File::File(std::string name, uintmax_t size): size(size) {
    std::cout << "construction of file @" << this << '\n';
    this->name = std::move(name);
}

File::~File() {
    std::cout << "destruction of file @" << this << '\n';
}

int File::mType() const {
    return FILE;
}

void File::ls(int indent) const {
    int j=0;
    while(j<((indent+4)*lev))
    {
        std::cout << " ";
        j++;
    }
    std::cout << this->name << " " << getSize() <<  '\n';
}

uintmax_t File::getSize() const {
    return size;
}