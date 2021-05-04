//
// Created by user on 03/04/2021.
//

#include "myList.h"

myList::myList() {
    _head = nullptr;
    _tail = nullptr;
    _current_el = nullptr;
}

myList::~myList() {

}

myList::nodes * myList::_new_node() {
    nodes *n = new (std::nothrow) nodes;
    if(n == nullptr)
    {
        std::cout << "errore allocazione nodo\n";
        return nullptr;
    }
    else
    {
        n->next = nullptr;
        return n;
    }
}

void myList::push_front(const MyClass &val) {
    myList::nodes *node = _new_node();
    node->value = val;
    if(_head == nullptr && _tail == nullptr)
    {
        node->next = nullptr;
        _head = _tail = node;
    }
    else
    {
        node->next = _head;
        _head = node;
    }
}

MyClass myList::popNode() {
    MyClass ret;
    _current_el = _head->next;
    ret = _head->value;
    delete _head;
    _head = _current_el;
    return ret;
}

void myList::push_back(const MyClass &val) {
    nodes *node = _new_node();
    node->value = val;
    if(_head == nullptr && _tail == nullptr)
    {
        node->next = nullptr;
        _head = _tail = node;
    }
    else
    {
        node->next = nullptr;
        _tail->next = node;
        _tail = node;
    }
}

void myList::insertNode(const MyClass &val, int pos) {
    nodes *elem = _new_node();
    int i=0;
    bool flag = false;
    elem->value = val;
    if(pos == 0)
    {
        push_front(val);
    }
    else
    {
        nodes *prec;
        for(_current_el = _head; _current_el != nullptr && flag == false; _current_el = _current_el->next)
        {
            if(i == pos)
            {
                flag = true;
                elem->next = _current_el;
                prec->next = elem;
                if(_current_el->next == nullptr) //coda
                    _tail = elem;
            }
            prec = _current_el;
            i++;
        }
    }
}

void myList::insertIncOrderedNode(const MyClass &val) {
    if(_tail == nullptr && _head == nullptr)
        push_front(val);
    else
    {
        bool last = true;
        nodes *prec = nullptr;
        for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        {
            if(val.getValue() < _current_el->value.getValue())
            {
                last = false;
                break;
            }
            prec = _current_el;
        }
        if(last == true)
            push_back(val);
        else
        {
            nodes *elem = _new_node();
            elem->value = val;
            elem->next = _current_el;
            if(prec != nullptr)
                prec->next = elem;
            else
                _head = elem;
        }
    }
}

void myList::insertDecOrderedNode(const MyClass &val) {
    if(_tail == nullptr && _head == nullptr)
        push_front(val);
    else
    {
        bool last = true;
        nodes *prec = nullptr;
        for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        {
            if(val.getValue() >= _current_el->value.getValue())
            {
                last = false;
                break;
            }
            prec = _current_el;
        }
        if(last == true)
            push_back(val);
        else
        {
            nodes *elem = _new_node();
            elem->value = val;
            elem->next = _current_el;
            if(prec != nullptr)
                prec->next = elem;
            else
                _head = elem;
        }
    }
}

void myList::deleteNodeByPos(const int &pos) {
    int i=0;
    nodes *n;
    if(pos == 0)
    {
        n = _head;
        _head = _head->next;
        delete n;
    }
    else if(pos > 0)
    {
        nodes *prec;
        for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        {
            if(i == pos)
            {
                n = _current_el;
                if(_current_el->next == nullptr) //ultimo elemento
                    _tail = prec;
                prec->next = _current_el->next;
                delete n;
                break;
            }
            i++;
            prec = _current_el;
        }
    }
}

void myList::deleteNodeByVal(const MyClass &val) {
    nodes *n;
    if(val.getValue() == _head->value.getValue())
    {
        n = _head;
        _head = _head->next;
        delete n;
    }
    else
    {
        nodes *prec;
        for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        {
            if(val.getValue() == _current_el->value.getValue())
            {
                n = _current_el;
                if(_current_el->next == nullptr) //ultimo elemento
                    _tail = prec;
                prec->next = _current_el->next;
                delete n;
                break;
            }
            prec = _current_el;
        }
    }
}

void myList::swapNodes(const int &pos0, const int &pos1) {
    nodes *n1, *n2, *prec0, *prec1;
    int i=0;
    for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
    {
        if(i == pos0)
        {
            n1 = _current_el;
            break;
        }
        prec0 = _current_el;
        i++;
    }
    i=0;
    for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
    {
        if(i == pos1)
        {
            n2 = _current_el;
            break;
        }
        prec1 = _current_el;
        i++;
    }
    if(pos0 != 0)
        prec0->next = n2;
    if(pos1 != 0)
        prec1->next = n1;
    nodes *swap;
    swap = n2->next;
    n2->next = n1->next;
    n1->next = swap;
    if(pos0 == 0)
        _head = n2;
    if(pos1 == 0)
        _head = n1;
    if(n1->next == nullptr)
        _tail = n1;
    if(n2->next == nullptr)
        _tail = n2;
}

MyClass myList::findNodeByPos(const int &pos) const {
    int i=0;
    nodes *elem;
    MyClass m;
    bool flag = false;
    for(elem = _head; elem != nullptr; elem = elem->next)
    {
        if(i == pos)
        {
            flag = true;
            m = elem->value;
        }
        i++;
    }
    if(flag == false)
        std::cout << "elemento non trovato\n";
    return m;
}

int myList::findNodeByVal(const MyClass& val) const {
    nodes *elem;
    int m=0;
    bool flag = false;
    for(elem = _head; elem != nullptr; elem = elem->next)
    {
        if(val.getValue() == elem->value.getValue())
        {
            flag = true;
            break;
        }
        m++;
    }
    if(flag == false)
        std::cout << "elemento non trovato\n";
    return m;
}

void myList::print() {
    for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        std::cout << _current_el->value.getValue() << '\n';
}

