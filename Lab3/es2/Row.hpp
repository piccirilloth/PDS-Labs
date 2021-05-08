//
// Created by user on 26/04/2021.
//

#ifndef ES2_ROW_HPP
#define ES2_ROW_HPP
#include <iostream>

template <typename T, typename R>
class Row {
    std::unique_ptr<T[]> _ptr;

public:
    Row(R n): _ptr(new T[n]) { };
    Row(): _ptr(nullptr) { };
    ~Row() {
        std::cout << "row destruction\n";
    };
    T & operator[](const T &index) const {
        return _ptr[index];
    };
    T & operator[](T &index) {
        return _ptr[index];
    };
    Row(const Row &val) = delete; //copy is forbidden
    Row(Row &&val) {
        std::cout << "row move called\n";
        _ptr.swap(val._ptr);
        val._ptr.reset();
    }

    Row& operator=(Row&& other) noexcept {
        std::cout << "row move called\n";
        _ptr.swap(other._ptr);
        other._ptr.reset();
        return *this;
    }
};

template <typename T, typename R>
std::ostream & operator<<(std::ostream &out, const Row<T, R> &r) {
    out << r[0];
    return out;
}

#endif //ES2_ROW_HPP
