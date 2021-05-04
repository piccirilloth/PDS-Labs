//
// Created by user on 19/04/2021.
//

#ifndef ES3_FILE_H
#define ES3_FILE_H
#include "Base.h"

class File: public Base {
    uintmax_t size;
public:
    File(std::string name, uintmax_t size);
    ~File();
    int File::mType() const;
    virtual void ls(int indent) const;
    uintmax_t getSize() const;
};


#endif //ES3_FILE_H
