#include <iostream>
#include "Matrix.hpp"
#include "Row.hpp"

int main() {
    Matrix<int, int> m(3,3);
    m.populate();
    // m.print();
    Row<int, int> r(3);
    r = std::move(m[1]); //after this the row 1 of the matrix does not exist anymore
    std::cout << r << '\n';
    return 0;
}
