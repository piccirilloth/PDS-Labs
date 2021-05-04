//
// Created by user on 21/04/2021.
//

#ifndef ES2_MATRIX_HPP
#define ES2_MATRIX_HPP
#include <iostream>
#include "Row.hpp"

template <typename T, typename R>
class Matrix {
public:
    Matrix(R r, R c);
    ~Matrix();
    void populate();
    void print();
    Row<T, R>& operator[](R i) const;
private:
    R righe;
    R colonne;
    std::unique_ptr<Row<T, R>[]> mat;
};

template <typename T, typename R>
Matrix<T, R>::Matrix(R r, R c): mat(new Row<T,R>[r]) {
    std::cout << "matrix construction\n";
    righe = r;
    colonne = c;
    //mat = new Row<T,R>[r];
    for(R i=0; i<righe; i++) {
        mat[i] = Row<T,R>(c);
    }
}

template <typename T, typename R>
Matrix<T, R>::~Matrix<T, R>() {
    std::cout << "matrix distruction\n";
}

template <typename T, typename R>
void Matrix<T, R>::populate() {
    for(R i=0; i<righe; i++)
        for(R j=0; j<colonne; j++)
            mat[i][j] = i;
}

template <typename T, typename R>
void Matrix<T, R>::print() {
    for(R i=0; i<righe; i++)
        for(R j=0; j<colonne; j++)
            std::cout << mat[i][j] << '\n';
}

template <typename T, typename R>
Row<T, R> & Matrix<T, R>::operator[](R i) const {
    return mat[i];
}

#endif //ES2_MATRIX_HPP
