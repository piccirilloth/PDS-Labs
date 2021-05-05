#include <iostream>
#include "MapperInput.h"
#include "Mapper.hpp"

int main() {
    MapperInput m("209.17.96.34 - - [01/Jan/2020:00:19:59+0100] \"GET / HTTP/1.1\" 200 20744");
    MapperInput m2("194.55.187.131 - - [01/Jan/2020:00:44:56+0100] \"GET /manager HTTP/1.1\" 404 1999");
    Mapper<MapperInput, Result> mapper;
    vector<Result> vect = mapper.map(m);
    mapper.map(m2);
    return 0;
}
