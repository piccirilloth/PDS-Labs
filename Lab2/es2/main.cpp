#include <iostream>
#include "Container.h"

int main() {
    Container c(10);
    for(int i=0; i<c.size(); i++)
        c[i] = i;
    for(int i=0; i<c.size(); i++)
        std::cout << c[i] << '\n';
    return 0;
}
