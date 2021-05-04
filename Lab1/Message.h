//
// Created by user on 24/03/2021.
//

#ifndef LAB1_MESSAGE_H
#define LAB1_MESSAGE_H
#include <iostream>
#include <string>

class Message {
    static long id_s;
    long id;
    char *data;
    int size;

public:
    Message();
    Message(int s);
    Message(const Message &m);
    Message(Message && m) noexcept;
    ~Message();
    Message& operator=(const Message & m);
    Message& operator=(Message && m);
    char * getData() const;
    void setData(int s);
    long getId() const;
    void setId(long id);
    int getSize() const;
    char * mkMessage(int n);
    friend std::ostream& operator<<(std::ostream &out, const Message &m);
};


#endif //LAB1_MESSAGE_H
