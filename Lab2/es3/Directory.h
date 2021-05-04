//
// Created by user on 11/04/2021.
//

#ifndef ES3_DIRECTORY_H
#define ES3_DIRECTORY_H
#include <iostream>
#include <map>
#include "Base.h"
#include "File.h"

class Directory: public std::enable_shared_from_this<Directory>, public Base {
    std::map<std::string, std::shared_ptr<Base>> child;
    std::weak_ptr<Directory> parent;
    std::weak_ptr<Directory> self;
    static std::shared_ptr<Directory> root;
    static bool first;
    int l;
    Directory();

public:
    static std::shared_ptr<Directory> makeDirectory(const std::string& name, std::weak_ptr<Directory> parent);
    ~Directory();
    void ls(int indent) const;
    std::shared_ptr<Directory> addDirectory(const std::string &nome);
    static std::shared_ptr<Directory> getRoot();
    std::shared_ptr<Base> get(std::string name);
    int mType() const;
    std::shared_ptr<File> addFile(const std::string& name, uintmax_t size);
    std::shared_ptr<Directory> getDir(const std::string& name);
    std::shared_ptr<File> getFile(const std::string& name);
    bool remove(const std::string& name);
};


#endif //ES3_DIRECTORY_H
