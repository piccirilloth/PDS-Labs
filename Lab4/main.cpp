#include <iostream>
#include <fstream>
#include "MapperInput.h"
#include "Mapper.hpp"
#include "Reducer.hpp"
#include "ReducerInput.h"
#include "map"

std::vector<std::map<std::string, int>> mapreduce(std::ifstream &fin, std::vector<Result> (*map) (const MapperInput&), std::pair<std::string, int> (*reduce) (const ReducerInput&)) {
    std::vector<std::map<std::string, int>> acc;
    std::vector<Result> r;
    std::string line;
    acc.resize(4);
    while(std::getline(fin, line)) {
        MapperInput m(line);
        r = map(m);
        std::cout << m.getTime() <<'\n';
        for(int j=0; j<r.size(); j++) {
            std::string key = r[j].getKey();
            int result = r[j].getValue();
            if(acc[j].find(key) == acc[j].end()) //key not found
                acc[j].insert(std::pair<std::string, int>(key, 0));
            std::pair<std::string, int> p = reduce(ReducerInput(key, result, acc[j].at(key)));
            acc[j].at(p.first) = p.second;
        }
    }
    return acc;
}

void openFile(std::ifstream &fin, std::string &fileName) {
    fin.open(fileName, ios::in);
    if(!fin.is_open()) {
        std::cout << "cannot open the input file " + fileName + '\n';
        return;
    }
}

//TODO: add file, handle a map for a single result, add concurrency

int main() {
    /*std::string m("209.17.96.34 - - [01/Jan/2020:00:19:59 +0100] \"GET / HTTP/1.1\" 200 20744");
    std::string m2("194.55.187.131 - - [01/Jan/2020:00:44:56 +0100] \"GET /manager HTTP/1.1\" 404 1999");
    std::string m3("209.17.96.34 - - [01/Jan/2020:00:19:59 +0100] \"GET /ciao HTTP/1.1\" 200 30000");
    Mapper<MapperInput, Result> mapper;
    Reducer<ReducerInput> reducer;
    std::vector<std::string> input;
    input.push_back(m);
    input.push_back(m2);
    input.push_back(m3);
    for(const auto &item : mapp) {
        std::cout << "key: " << item.first << " value: "  << item.second << '\n';
    }*/

    std::ifstream fin;
    std::string fileName = "../input.txt";
    openFile(fin, fileName);
    std::vector<std::map<std::string, int>> results = mapreduce(fin, Mapper<MapperInput, Result>::map, Reducer<ReducerInput>::reduce);
    int i = 0;
    for (const auto &item : results) {
        std::cout << "map number " << ++i << '\n';
        for (const auto &item1 : item) {
            std::cout << "key = " << item1.first << " value = " << item1.second << '\n';
        }
    }
    return 0;
}
