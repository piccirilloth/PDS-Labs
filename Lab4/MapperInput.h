//
// Created by oscar on 05/05/21.
//

#ifndef LAB4_MAPPERINPUT_H
#define LAB4_MAPPERINPUT_H
#include <iostream>
#include <string>
#include "stdio.h"

using namespace std;

class MapperInput {
private:
    string ipAddress;
    string timestamp;
    string method;
    string url;
    string protocol;
    string code;
    string size;

public:
    MapperInput(string row);
    ~MapperInput();

    const string &getIpAddress() const;
    void setIpAddress(const string &ipAddress);
    const string &getTimestamp() const;
    void setTimestamp(const string &timestamp);
    const string &getMetodo() const;
    void setMetodo(const string &metodo);
    const string &getUrl() const;
    void setUrl(const string &url);
    const string &getProtocollo() const;
    void setProtocollo(const string &protocollo);
    const string &getCode() const;
    void setCode(const string &code);
    const string &getSize() const;
    void setSize(const string &size);
    string getTime() const;
};


#endif //LAB4_MAPPERINPUT_H
