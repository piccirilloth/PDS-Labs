//
// Created by picci on 04/06/2021.
//

#include "Row.h"

Row::Row(int nRow, std::string row, std::string fileName): nRow(nRow), row(row), fileName(fileName) {}

Row & Row::operator=(const Row &other) {
    this->nRow = other.getNRow();
    this->fileName = other.getFileName();
    this->row = other.getRow();
    return *this;
}

Row::Row() {
    nRow = -1;
    fileName = "";
    row = "";
}

Row::Row(const Row &r) {
    this->nRow = r.nRow;
    this->fileName = r.fileName;
    this->row = r.row;
}

int Row::getNRow() const {
    return nRow;
}

void Row::setNRow(int nRow) {
    Row::nRow = nRow;
}

const std::string &Row::getRow() const {
    return row;
}

void Row::setRow(const std::string &row) {
    Row::row = row;
}

const std::string &Row::getFileName() const {
    return fileName;
}

void Row::setFileName(const std::string &fileName) {
    Row::fileName = fileName;
}
