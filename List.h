//
// Created by Macbook Pro on 06/02/2020.
//

#ifndef UNTITLED5_LIST_H
#define UNTITLED5_LIST_H

#include "Elem.h"
class List {
public:
    List();
    ~List();
    Elem* getHead();
    Elem* getTail();
    void operator+=(int);
    void print();

private:
    Elem* head_;
    Elem* tail_;
};
#endif //UNTITLED5_LIST_H
