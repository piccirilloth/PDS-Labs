//
// Created by user on 30/03/2021.
//

#include "MessageStore.h"

MessageStore::MessageStore(int n) {
    std::cout << "creating MessageStore\n";
    this->n = n;
    this->dim = 0;
    messages = new Message[this->n];
}

MessageStore::~MessageStore() {
    std::cout << "deleting messageStore\n";
    delete[] messages;
}

void MessageStore::add(Message &m) {
    for(int i=0; i<dim; i++)
        if(messages[i].getId() == m.getId() || m.getId() == -1)
        {
            messages[i] = m;
            return;
        }
    if(dim < n)
    {
        messages[dim] = m;
        dim++;
    }
    else
    {
        n = n + dim;
        Message *mes = new (std::nothrow) Message[dim];
        if(mes == nullptr)
        {
            std::cout << "ERRORE ALLOCAZIONE MES\n";
        }
        else
        {
            for(int i=0; i<dim; i++)
                mes[i] = std::move(messages[i]);
            delete[] messages;
            messages = new (std::nothrow) Message[n];
            if(messages == nullptr)
            {
                std::cout << "ERRORE ALLOCAZIONE MESAGES\n";
            }
            else
            {
                for(int i=0; i<dim; i++)
                    messages[i] = std::move(mes[i]);
                delete[] mes;
            }
            messages[dim] = m;
            dim++;
        }
    }
}

std::optional<Message> MessageStore::get(long id) {
    for(int i=0; i<dim; i++)
        if(messages[i].getId() == id)
            return messages[i];
    return std::nullopt;
}

bool MessageStore::remove(long id) {
    bool flag = false;
    for(int i=0; i<dim; i++){
        if(messages[i].getId() == id)
        {
            flag = true;
            messages[i].setId(-1);
            //messages[i].setData(0);
            break;
        }
    }
    return flag;
}

std::tuple<int, int> MessageStore::stats() {
    int validi = 0;
    int vuoti = 0;
    for(int i=0; i<dim; i++)
        if(messages[i].getId() == -1)
            vuoti++;
        else
            validi++;
    return std::make_tuple(validi, vuoti);
}

void MessageStore::compact() {
    int count=0;
    for(int i=0; i<dim; i++)
        if(messages[i].getId() != -1)
            count++;
    Message *m = new (std::nothrow) Message[count];
    if(m == nullptr)
    {
        std::cout << "ERRORE ALLOCAZIONE\n";
        return;
    }
    for(int i=0, j=0; i<dim; i++)
        if(messages[i].getId() != -1)
            m[j++] = std::move(messages[i]);
    delete[] messages;
    messages = new (std::nothrow) Message[count];
    if(messages == nullptr)
    {
        std::cout << "ERRORE ALLOCAZIONE\n";
        return;
    }
    for(int i=0; i<count; i++)
        messages[i] = std::move(m[i]);
    delete[] m;
    dim = count;
}


int MessageStore::getDim() {
    return this->dim;
}

void MessageStore::printMessages() {
    for(int i=0; i<dim; i++)
        std::cout << messages[i] << '\n';
}