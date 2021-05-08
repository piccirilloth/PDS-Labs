#include <iostream>
#include "MapperInput.h"
#include "Mapper.hpp"
#include "Reducer.hpp"
#include "ReducerInput.h"
#include "map"

std::map<std::string, int> mapreduce(std::vector<std::string> input, std::vector<Result> (*map) (const MapperInput&), std::pair<std::string, int> (*reduce) (const ReducerInput&));

//TODO: add file, handle a map for a single result, add concurrency

int main() {
    std::string m("209.17.96.34 - - [01/Jan/2020:00:19:59 +0100] \"GET / HTTP/1.1\" 200 20744");
    std::string m2("194.55.187.131 - - [01/Jan/2020:00:44:56 +0100] \"GET /manager HTTP/1.1\" 404 1999");
    std::string m3("209.17.96.34 - - [01/Jan/2020:00:19:59 +0100] \"GET /ciao HTTP/1.1\" 200 30000");
    Mapper<MapperInput, Result> mapper;
    Reducer<ReducerInput> reducer;
    std::vector<std::string> input;
    input.push_back(m);
    input.push_back(m2);
    input.push_back(m3);
    std::vector<Result> (*map) (MapperInput&);
    std::map<std::string, int> mapp = mapreduce(input, mapper.map, reducer.reduce);
    for(const auto &item : mapp) {
        std::cout << "key: " << item.first << " value: "  << item.second << '\n';
    }
    //std::cout << m.getTimestamp() << '\n';
    //vector<Result> vect = mapper.map(m);
    ///mapper.map(m2);*/
    return 0;
}

std::map<std::string, int> mapreduce(std::vector<std::string> input, std::vector<Result> (*map) (const MapperInput&), std::pair<std::string, int> (*reduce) (const ReducerInput&)) {
    std::map<std::string, int> acc;
    std::vector<Result> r;
    for(int i=0; i<3; i++) {
        MapperInput m(input[i]);
        r = map(m);
        for(int j=0; j<r.size(); j++) {
            std::string key = r[j].getKey();
            int result = r[j].getValue();
            if(acc.find(key) == acc.end()) //key not found
                acc.insert(std::pair<std::string, int>(key, 0));
            std::pair<std::string, int> p = reduce(ReducerInput(key, result, acc.at(key)));
            acc.at(p.first) = p.second;
        }
    }
    return acc;
}
