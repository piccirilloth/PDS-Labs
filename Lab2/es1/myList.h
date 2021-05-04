//
// Created by user on 03/04/2021.
//

#ifndef LAB2_MYLIST_H
#define LAB2_MYLIST_H
#include "MyClass.h"
#include <iostream>


class myList {
public:
    myList();
    ~myList();
    /* Insert an element at the head of the list . Current element moved to
        the new head .*/
    void push_front (const MyClass& val);
    /* Return the value of the node at the head of the list and delete the
        head node . Current element moved to the new head . */
    MyClass popNode();
    /* Insert an element at the tail of the list . Current element moved to
        the tail . */
    void push_back(const MyClass& val);
    /* Insert an element at the pos -th element of the list . Current
        element moved to the new element */
    void insertNode(const MyClass& val, int pos);
    /* Insert an element in a sorted list with increasing values . Current
        element moved to the new element .*/
    void insertIncOrderedNode(const MyClass& val);
    /* Insert an element in a sorted list with decreasing values . Current
        element moved to the new element .*/
    void insertDecOrderedNode(const MyClass& val);
    /* Delete the pos -th node of the list . Current element moved to the
        pos -th previous element . */
    void deleteNodeByPos(const int& pos);
    /* Delete all the nodes of the list containing val . Current element
        moved to the previous element of the deleted element .*/
    void deleteNodeByVal(const MyClass& val);
    /* Swap the content of nodes at pos0 and pos1 . Current element moved
        to the pos0 -th element . */
    void swapNodes (const int& pos0, const int& pos1);
    /* Return the value of the pos -th node . Current element moved to the
        found element .*/
    MyClass findNodeByPos(const int& pos) const;
    /* Return the position of the first occurrence of a node containing
        val . Current element moved to the found element . */
    int findNodeByVal(const MyClass& val) const;
    void print();
private:
    typedef struct listNode
    {
        MyClass value;
        struct listNode *next;
    } nodes;

    nodes *_head, *_tail , *_current_el;

    // Return the pointer to a new node
    nodes *_new_node();
};


#endif //LAB2_MYLIST_H
