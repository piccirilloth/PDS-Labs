//
// Created by user on 21/04/2021.
//

#ifndef ES1_MYLIST_HPP
#define ES1_MYLIST_HPP

#include <iostream>

template <typename T>
class MyList {
public:
    MyList();
    ~MyList();
    /* Insert an element at the head of the list . Current element moved to
    the new head .*/
    void push_front (const T& val);
    /* Return the value of the node at the head of the list and delete the
        head node . Current element moved to the new head . */
    T popNode();
    /* Insert an element at the tail of the list . Current element moved to
        the tail . */
    void push_back(const T& val);
    /* Insert an element at the pos -th element of the list . Current
        element moved to the new element */
    void insertNode(const T& val, int pos);
    /* Insert an element in a sorted list with increasing values . Current
        element moved to the new element .*/
    void insertIncOrderedNode(const T& val);
    /* Insert an element in a sorted list with decreasing values . Current
        element moved to the new element .*/
    void insertDecOrderedNode(const T& val);
    /* Delete the pos -th node of the list . Current element moved to the
        pos -th previous element . */
    void deleteNodeByPos(const int& pos);
    /* Delete all the nodes of the list containing val . Current element
        moved to the previous element of the deleted element .*/
    void deleteNodeByVal(const T& val);
    /* Swap the content of nodes at pos0 and pos1 . Current element moved
        to the pos0 -th element . */
    void swapNodes (const int& pos0, const int& pos1);
    /* Return the value of the pos -th node . Current element moved to the
        found element .*/
    T findNodeByPos(const int& pos) const;
    /* Return the position of the first occurrence of a node containing
        val . Current element moved to the found element . */
    int findNodeByVal(const T& val) const;
    void print();
private:
    struct nodes
    {
        T value;
        struct nodes *next;
    };

    nodes *_head, *_tail , *_current_el;
    // Return the pointer to a new node
    nodes *_new_node();
};

template<typename T>
MyList<T>::MyList () {
    _head = nullptr;
    _tail = nullptr;
    _current_el = nullptr;
}

template<typename T>
MyList<T>::~MyList() {

}

template<typename T>
typename MyList<T>::nodes * MyList<T>::_new_node() {
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

template<typename T>
void MyList<T>::push_front(const T &val) {
    nodes *node = _new_node();
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

template <typename T>
T MyList<T>::popNode() {
    T ret;
    _current_el = _head->next;
    ret = _head->value;
    delete _head;
    _head = _current_el;
    if(_head == nullptr)
        _tail = nullptr;
    return ret;
}

template <typename T>
void MyList<T>::push_back(const T &val) {
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

template <typename T>
void MyList<T>::insertNode(const T &val, int pos) {
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
                if(_current_el->next == nullptr) {
                    elem->next = nullptr;
                    _current_el->next = elem;
                    prec->next = _current_el;
                    _tail = elem;
                }
                else {
                    flag = true;
                    elem->next = _current_el;
                    prec->next = elem;
                }
            }
            prec = _current_el;
            i++;
        }
    }
}

template <typename T>
void MyList<T>::insertIncOrderedNode(const T &val) {
    if(_tail == nullptr && _head == nullptr)
        push_front(val);
    else
    {
        bool last = true;
        nodes *prec = nullptr;
        for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        {
            if(val < _current_el->value)
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

template <typename T>
void MyList<T>::insertDecOrderedNode(const T &val) {
    if(_tail == nullptr && _head == nullptr)
        push_front(val);
    else
    {
        bool last = true;
        nodes *prec = nullptr;
        for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        {
            if(val >= _current_el->value)
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

template <typename T>
void MyList<T>::deleteNodeByPos(const int &pos) {
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

template <typename T>
void MyList<T>::deleteNodeByVal(const T &val) {
    nodes *n;
    if(val == _head->value)
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
            if(val == _current_el->value)
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

template <typename T>
void MyList<T>::swapNodes(const int &pos0, const int &pos1) {
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

template <typename T>
T MyList<T>::findNodeByPos(const int &pos) const {
    int i=0;
    nodes *elem;
    T m;
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

template <typename T>
int MyList<T>::findNodeByVal(const T& val) const {
    nodes *elem;
    int m=0;
    bool flag = false;
    for(elem = _head; elem != nullptr; elem = elem->next)
    {
        if(val == elem->value)
        {
            flag = true;
            break;
        }
        m++;
    }
    if(flag == false)
    {
        std::cout << "elemento non trovato\n";
        return -1;
    }
    return m;
}

template <typename T>
void MyList<T>::print() {
    for(_current_el = _head; _current_el != nullptr; _current_el = _current_el->next)
        std::cout << _current_el->value << '\n';
}

#endif //ES1_MYLIST_HPP