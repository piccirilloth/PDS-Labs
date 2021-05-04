//
// Created by user on 19/04/2021.
//

#ifndef ES3_BASE_H
#define ES3_BASE_H
#include <iostream>

#define FILE 0
#define DIRECTORY 1

class Base {
protected:
    std::string name;
    int lev;
public:
    std::string getName() const;
    virtual int mType()const = 0;
    virtual void ls(int indent) const = 0;
    virtual void setLevel(int val);
};


#endif //ES3_BASE_H
