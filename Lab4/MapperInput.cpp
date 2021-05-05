//
// Created by oscar on 05/05/21.
//

#include "MapperInput.h"

#define N 32

MapperInput::MapperInput(string row) {
    char ip[N], time[N], method[N], url[N], protocol[N], code[N], size[N];
    sscanf(row.data(), "%s - - [%s \"%s %s %s %s %s", ip, time, method, url, protocol, code, size);
    this->ipAddress.assign(ip);
    this->timestamp.assign(time).erase(this->timestamp.length()-1, 1);
    this->method.assign(method);
    this->url.assign(url);
    this->protocol.assign(protocol).erase(this->protocol.length()-1), 1;
    this->code.assign(code);
    this->size.assign(size);
}

MapperInput::~MapperInput() {
    cout << "calling destructor of MapperInput\n";
}

const string &MapperInput::getIpAddress() const {
    return ipAddress;
}

const string &MapperInput::getTimestamp() const {
    return timestamp;
}

void MapperInput::setIpAddress(const string &ipAddress) {
    MapperInput::ipAddress = ipAddress;
}

void MapperInput::setTimestamp(const string &timestamp) {
    MapperInput::timestamp = timestamp;
}

const string &MapperInput::getMetodo() const {
    return method;
}

void MapperInput::setMetodo(const string &metodo) {
    MapperInput::method = metodo;
}

const string &MapperInput::getUrl() const {
    return url;
}

void MapperInput::setUrl(const string &url) {
    MapperInput::url = url;
}

const string &MapperInput::getProtocollo() const {
    return protocol;
}

void MapperInput::setProtocollo(const string &protocollo) {
    MapperInput::protocol = protocollo;
}

const string &MapperInput::getCode() const {
    return code;
}

void MapperInput::setCode(const string &code) {
    MapperInput::code = code;
}

const string &MapperInput::getSize() const {
    return size;
}

void MapperInput::setSize(const string &size) {
    MapperInput::size = size;
}

string MapperInput::getTime() const {
    char time[2];
    time[0] = this->timestamp.at(12);
    time[1] = this->timestamp.at(13);
    string ret(time);
    return ret;
}
