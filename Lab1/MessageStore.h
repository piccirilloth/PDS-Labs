//
// Created by user on 30/03/2021.
//

#ifndef LAB1_MESSAGESTORE_H
#define LAB1_MESSAGESTORE_H
#include "Message.h"
#include <iostream>
#include <optional>

class MessageStore {
    Message * messages;
    int dim;
    int n;
public:
    MessageStore(int n);
    ~MessageStore();
    void add ( Message & m );
    std::optional<Message> get ( long id );
    bool remove ( long id );
    std :: tuple <int , int > stats ();
    void compact ();
    int getDim();
    void printMessages();
};


#endif //LAB1_MESSAGESTORE_H
