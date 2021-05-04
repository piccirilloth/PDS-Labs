#include <iostream>
#include "Directory.h"

int main() {
    std::shared_ptr<Directory> r = Directory::getRoot();
    std::shared_ptr<Directory> child1 = r->addDirectory("child1");
    std::shared_ptr<Directory> child2 = r->addDirectory("child2");
    std::shared_ptr<Directory> child11 = child1->addDirectory("child1.1");
    std::shared_ptr<Directory> child21 = child2->addDirectory("child2.1");
    std::shared_ptr<Directory> child211 = child21->addDirectory("child2.1.1");
    child1->addFile("file1.1", 10);
    child2->addFile("file2.1", 20);
    child2->addFile("file2.2", 30);
    child211->addFile("file2.1.1", 60);
    std::shared_ptr<Directory> f = child1->getDir("..");
    f->ls(0);

    /*child1->ls(0);
    bool ret = child1->remove("file1.1");
    if(ret == true)
        std::cout << "file1.1 deleted\n";
    ret = child1->remove("child1.1");
    if(ret == true)
        std::cout << "child1.1 deleted\n";*/
    child2->ls(0);
    return 0;
}
