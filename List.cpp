//
// Created by Macbook Pro on 06/02/2020.
//

#include "List.h"
#include <iostream>

List::List(): tail_(nullptr), head_(nullptr) {
}

Elem *List::getHead() {
    head_;
}

Elem *List::getTail() {
    return tail_;
}

void List::operator+=(int value) {
    if (head_ == nullptr) {
        head_ = new Elem(value, nullptr);
        tail_ = head_;
        return;
    }
    Elem* curr = head_;
    if (head_->getValue() > value) {
        head_ = new Elem(value, curr);
    } else if (tail_->getValue() < value) {
        tail_->setNext(new Elem(value, nullptr));
        tail_ = tail_->getNext();
    } else{
        while(curr != nullptr) {
            if (curr->getValue() == value) {
                std::cerr << value << " is in List now" << std::endl;
                return;
            } else if (curr->getValue() > value)
            {
                int tmpValue = curr->getValue();
                Elem* tmpPointer = curr->getNext();
                curr->setValue(value);
                curr->setNext(new Elem(tmpValue, tmpPointer));
                if (curr == tail_) {
                    tail_ = curr->getNext();
                }
                return;
            }
            curr = curr->getNext();
        }
    }
}

void List::print() {
    Elem* curr = head_;
    do {
        cout << curr->getValue() << ' ';
        curr = curr->getNext();
    } while (curr != nullptr);
}

List::~List() {

}


