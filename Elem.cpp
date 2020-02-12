//
// Created by Macbook Pro on 06/02/2020.
//

#include "Elem.h"

Elem::Elem(int value, Elem* next): value_(value), next_(next) {
}

Elem *&Elem::getNext() {
    return next_;
}

int Elem::getValue() const{
    return value_;
}

void Elem::setValue(int value) {
    value_ = value;
}

void Elem::setNext(Elem * next) {
    next_ = next;
}

