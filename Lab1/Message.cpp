//
// Created by user on 24/03/2021.
//

#include "Message.h"

Message::Message() {
    std::cout << "default constructor\n";
    id = -1;
    this->data = new (std::nothrow) char;
    if(this->data == nullptr)
        std::cout << "error occoured in create data\n";
    else
        this->data = mkMessage(0);
    this->size=0;
}

Message::Message(int s) {
    std::cout << "size constructor\n";
    this->size = s;
    this->data = new (std::nothrow) char[s+1];
    if(this->data == nullptr)
        std::cout << "error occoured in create data\n";
    else
        this->data = mkMessage(s);
    id = id_s++;
}

Message::~Message() {
    std::cout << "calling distructor\n";
    if(this->data == nullptr) {
        delete[] this->data;
        this->data = nullptr;
    }
}

Message::Message(const Message &m) {
    std::cout << "calling copy costructor\n";
    this->id = m.id;
    this->size = m.size;
    this->data = new (std::nothrow) char[this->size+1];
    if(this->data == nullptr || m.data == nullptr)
        std::cout << "errore nella creazione della copia\n";
    else
        std::memcpy(this->data, m.data, this->size+1);
}

Message::Message(Message &&m) noexcept{
    std::cout << "calling move constructor\n";
    this->id = m.id;
    this->size = m.size;
    this->data = new (std::nothrow) char[this->size+1];
    if(this->data == nullptr || m.data == nullptr)
        std::cout << "errore nella creazione della copia\n";
    else
        std::memcpy(this->data, m.data, this->size);
    this->data = m.data;
    m.data = nullptr;
}

int Message::getSize() const {
    return size;
}

char * Message::getData() const {
    char *d = new char[size+1];
    strcpy(d, data);
    return d;
}

Message& Message::operator=(const Message &m) {
    std::cout << "operator=" << '\n';
    if(this != &m) {
        delete[] this->data;
        this->data = nullptr;
        this->id = m.id;
        this->size = m.size;
        this->data = new (std::nothrow) char[this->size+1];
        if(this->data == nullptr || m.data == nullptr)
            std::cout << "errore nella creazione della copia\n";
        else
            std::memcpy(this->data, m.data, this->size+1);
    }
    return *this;
}

Message & Message::operator=(Message &&m) {
    if(this != &m)
    {
        std::cout << "movement operator\n";
        delete[] this->data;
        this->size = m.size;
        this->id = m.id;
        this->data = m.data;
        m.data = nullptr;
    }
    return *this;
}

void Message::setId(long id) {
    this->id = id;
}

long Message::getId() const {
    return id;
}

void Message::setData(int s) {
    if(this->data != nullptr)
    {
        delete[] this->data;
        this->data = nullptr;
    }
    this->size = s;
    this->data = new char[this->size+1];
    if(this->data == nullptr)
        std::cout << "allocation of data went wrong" << '\n';
    this->data = mkMessage(this->size);
    if(this->id == -1)
        this->id = id_s++;
}

char * Message::mkMessage(int n) {
    std::string vowels = " aeiou ";
    std::string consonants = " bcdfghlmnpqrstvz ";
    char * m = new ( std :: nothrow ) char [ n +1];
    if ( m != nullptr ) {
        for (int i = 0; i < n ; i ++){
            m [ i ] = i %2 ? vowels [ rand ()% vowels . size ()] :
                        consonants [ rand ()% consonants . size ()];
            }
        m [ n ] = '\0';
        }
    return m ;
}

std::ostream &operator<<(std::ostream &out, const Message &m) {
    std::string s(m.getData());
    out << "[id:" << m.getId() << "]" << "[size:" << m.getSize() << "]" << "[data:"
        << s.substr (0 , 20) << "]";
    return out;
}

