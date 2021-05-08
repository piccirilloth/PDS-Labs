#include <iostream>
#include "Matrix.hpp"
#include "Row.hpp"

int main() {
    Matrix<int, int> m(3,3);
    m.populate();
    // m.print();
    Row<int, int> r(3);
    //r = std::move(m[1]); //after this the row 1 of the matrix does not exist anymore
    //std::cout << r << '\n';
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m[i][j] = 1;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            std::cout << m[i][j] << ' ';
        std::cout << '\n';
    }
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m[i][j] = 10;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
            std::cout << m[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}
