//
// Created by user on 11/04/2021.
//

#include "Directory.h"

std::shared_ptr<Directory> Directory::root = std::shared_ptr<Directory>(nullptr);
bool Directory::first = true;

Directory::Directory() {
    std::cout << "creation @" << this << '\n';
    l=0;
}

Directory::~Directory() {
    std::cout << "destruction @" << this << '\n';
}

std::shared_ptr<Directory> Directory::makeDirectory(const std::string &name, std::weak_ptr<Directory> parent) {
    std::shared_ptr<Directory> dir(new Directory());
    dir->parent = parent;
    dir->self = dir;
    dir->name = name;
    return dir;
}

std::shared_ptr<Directory> Directory::addDirectory(const std::string &nome) {
    std::shared_ptr<Directory> dir;
    //std::cout << "addDirectory called\n";
    if(nome == "." || nome == "..")
        return std::shared_ptr<Directory>(nullptr);
    dir = makeDirectory(nome, this->shared_from_this());
    dir->setLevel(l+1);
    if(this->child.insert({nome, dir}).second == false)
        return std::shared_ptr<Directory>(nullptr);
    //std::cout << "child creater: father: " << this->child.at(nome)->parent.lock()->name << " name: " << this->child.at(nome)->name <<'\n';
    return dir;
}

std::shared_ptr<Directory> Directory::getRoot() {
    if(first == true) {
        first = false;
        root = makeDirectory("/", std::shared_ptr<Directory>(nullptr));
    }
    return root;
}

std::shared_ptr<Base> Directory::get(std::string name) {
    if(name == ".")
        return shared_from_this();
    if(name == "..")
        return this->parent.lock();
    else
    {
        try {
            std::shared_ptr<Base> c = child.at(name);
            return c;
        } catch(std::out_of_range) {
            std::cout << "the child does not exist!\n";
            return std::shared_ptr<Base>(nullptr);
        }
    }
}

void Directory::ls(int indent) const {
    static int level = 0;
    if(level == 0)
        std::cout << this->name << '\n';
    else
    {
        int j=0;
        while(j<((indent+4)*level))
        {
            std::cout << " ";
            j++;
        }
        std::cout << this->name << '\n';
    }
    if(this->child.size() == 0)
        return;
    for(auto iter = child.begin(); iter != child.end(); iter++)
    {
        level++;
        if(iter->second->mType() == DIRECTORY)
            iter->second->ls(indent);
        else if(iter->second->mType() == FILE)
        {
            iter->second->setLevel(level);
            iter->second->ls(indent);
        }
        level--;
    }
}

int Directory::mType() const {
    return DIRECTORY;
}

std::shared_ptr<File> Directory::addFile(const std::string &name, uintmax_t size) {
    std::shared_ptr<File> file = std::make_shared<File>(name, size);
    file->setLevel(this->l+1);
    if (this->child.insert({name, file}).second == false)
        return std::shared_ptr<File>(nullptr);
    return file;
}

std::shared_ptr<Directory> Directory::getDir(const std::string &name) {
    std::shared_ptr<Base> b = get(name);
    return std::dynamic_pointer_cast<Directory>(b);
}

std::shared_ptr<File> Directory::getFile(const std::string &name) {
    std::shared_ptr<Base> b = get(name);
    return std::dynamic_pointer_cast<File>(b);
}

bool Directory::remove(const std::string &name) {
    size_t ret;
    ret = this->child.erase(name);
    if(ret == 1)
        return true;
    else
        return false;
}