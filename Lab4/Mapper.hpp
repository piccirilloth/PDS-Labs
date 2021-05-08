//
// Created by oscar on 05/05/21.
//

#ifndef LAB4_MAPPER_HPP
#define LAB4_MAPPER_HPP
#include "MapperInput.h"
#include "Result.h"
#include <vector>

template <typename MapperInputT, typename ResultT>
class Mapper {
private:


public:
    //static std::vector<ResultT> results;
    static std::vector<ResultT> map(const MapperInputT& input) {
        std::vector<ResultT> results;
        results.clear();
        // key=IP
        results.push_back(ResultT(input.getIpAddress(), 1));
        // key=time
        results.push_back(ResultT(input.getTime(), 1));
        // key=url
        results.push_back(ResultT(input.getUrl(), 1));
        // key=code-ipaddress
        std::string s(input.getCode());
        s.append("-");
        s.append(input.getIpAddress());
        results.push_back(ResultT(s, 1));
        return results;
    }
};

#endif //LAB4_MAPPER_HPP
