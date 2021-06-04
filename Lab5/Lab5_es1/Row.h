//
// Created by picci on 04/06/2021.
//

#ifndef LAB5_ROW_H
#define LAB5_ROW_H
#include <string>

class Row {
    int nRow;
    std::string row;
    std::string fileName;
public:
    Row(int nRow, std::string row, std::string fileName);
    Row(Row const &r);
    Row();


    Row& operator=(const Row& other);

    int getNRow() const;

    void setNRow(int nRow);

    const std::string &getRow() const;

    void setRow(const std::string &row);

    bool isLast() const;

    void setLast(bool last);

    const std::string &getFileName() const;

    void setFileName(const std::string &fileName);
};


#endif //LAB5_ROW_H
