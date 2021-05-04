#include <iostream>
#include "MyList.hpp"
#include "MyClass.h"

int main() {
    MyList<int> list;
    list.push_front(1);
    list.push_back(2);
    list.push_back(3);
    list.insertNode(4, 2);
    list.insertIncOrderedNode(5);
    list.insertIncOrderedNode(0);
    list.deleteNodeByPos(0);
    list.deleteNodeByPos(4);
    list.deleteNodeByPos(2);
    list.insertIncOrderedNode(3);
    list.insertIncOrderedNode(7);
    list.insertIncOrderedNode(8);
    /*list.deleteNodeByVal(1);
    list.deleteNodeByVal(8);
    list.deleteNodeByVal(4);*/
    list.swapNodes(0, 5);
    list.swapNodes(3, 4);
    std::cout << "l'elemento in posizione 0 e' " << list.findNodeByPos(0) << '\n';
    std::cout << "l'elemento in posizione 5 e' " << list.findNodeByPos(5) << '\n';
    std::cout << "l'elemento in posizione 2 e' " << list.findNodeByPos(2) << '\n';
    /*std::cout << "l'elemento in valore 0 e' " << list.findNodeByVal(0) << '\n';
    std::cout << "l'elemento in valore 5 e' " << list.findNodeByVal(5) << '\n';
    std::cout << "l'elemento in valore 2 e' " << list.findNodeByVal(2) << '\n';*/
    list.print();
    return 0;
}
