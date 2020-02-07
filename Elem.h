//
// Created by Macbook Pro on 10/12/2019.
//

#pragma once
#include "String.h"
using namespace std;
class Elem
{
public:
    Elem(int, Elem*);
    Elem* & getNext();
    void setValue(int value);
    void setNext(Elem *);
    int getValue();
private:
    Elem* next_;
    int value_;
};
