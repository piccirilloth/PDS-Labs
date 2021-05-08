//
// Created by picci on 08/05/2021.
//

#ifndef LAB4_REDUCER_HPP
#define LAB4_REDUCER_HPP

#endif //LAB4_REDUCER_HPP
#include "ReducerInput.h"

template <typename ReducerInputT>
class Reducer {
public:
    static std::pair<std::string, int> reduce(const ReducerInputT& r) {
        int acc = r.getAcc() + r.getValue();
        return std::make_pair(r.getKey(), acc);
    }
};