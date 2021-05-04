//
// Created by user on 21/04/2021.
//

#ifndef ES3_RECURSIVE_HPP
#define ES3_RECURSIVE_HPP
#include <iostream>
#include <map>

template <typename T>
class Recursive: public std::enable_shared_from_this<T> {
    std::map<std::string, std::shared_ptr<T>> child;
    std::weak_ptr<T> parent;
    std::weak_ptr<T> self;
    static std::shared_ptr<T> root;
    static bool first;
    int l;
    Recursive();
public:
    static std::shared_ptr<T> makeRecursive(const std::string& name, std::weak_ptr<T> parent);
    ~Recursive();
    void ls(int indent) const;
    std::shared_ptr<T> addRecursive(const std::string &nome);
    static std::shared_ptr<T> getRoot();
    std::shared_ptr<T> get(std::string name);
    int mType() const;
    //std::shared_ptr<T> addFile(const std::string& name, uintmax_t size);
    //std::shared_ptr<Directory> getDir(const std::string& name);
    //std::shared_ptr<File> getFile(const std::string& name);
    bool remove(const std::string& name);
};

template <typename T>
std::shared_ptr<T> root = std::shared_ptr<Directory>(nullptr);
bool first = true;

template <typename T>
Recursive<T>::Recursive() {
    std::cout << "creation @" << this << '\n';
    l=0;
}

template <typename T>
Recursive<T>::~Recursive() {
    std::cout << "destruction @" << this << '\n';
}

template <typename T>
std::shared_ptr<T> Recursive<T>::makeRecursive(const std::string &name, std::weak_ptr<T> parent) {
    std::shared_ptr<T> rec(new T());
}

#endif //ES3_RECURSIVE_HPP
