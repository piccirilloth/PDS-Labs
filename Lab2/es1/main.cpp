#include <iostream>
#include "myList.h"
#include "MyClass.h"

int main() {
    MyClass m0(0), m1(1), m2(2), m3(3), m4(4), m5(55), m6(66), m7(8);
    myList list;

    list.insertIncOrderedNode(m1);
    list.insertIncOrderedNode(m2);
    list.insertIncOrderedNode(m5);
    list.insertIncOrderedNode(m4);
    list.insertIncOrderedNode(m3);
    list.insertIncOrderedNode(m0);
    list.insertIncOrderedNode(m6);
    list.insertIncOrderedNode(m7);
    list.print();
    std::cout << "swap elemento 3 con elemento 4\n";
    list.swapNodes(3, 4);
    list.print();
    std::cout << "elemento in posizione 3\n";
    std::cout << list.findNodeByPos(3).getValue() << '\n';
    std::cout << "posizione dell'elemento con valore 0: " << list.findNodeByVal(m0) << '\n';
    return 0;
}
