//
// Created by Macbook Pro on 06/02/2020.
//

#include "List.h"
#include <iostream>

List::List(): tail_(nullptr), head_(nullptr) {
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

List::~List() {
    while(head_ != nullptr) {
        Elem * curr = head_;
        head_ = head_->getNext();
        delete(curr);
    }
}

List::List(List && second): head_(second.head_), tail_(second.tail_) {
    second.head_ = nullptr;
    second.tail_ = nullptr;
}

std::ostream &operator<<(std::ostream &out, const List &list) {
    Elem* curr = list.head_;
    while (curr != nullptr) {
        out << curr->getValue() << ' ';
        curr = curr->getNext();
    }
    return out;
}

bool List::operator==(const List &second) const {
    Elem* firstPointer = head_;
    Elem* secondPointer = second.head_;
    while((firstPointer != nullptr) && (secondPointer != nullptr)) {
        if (firstPointer->getValue() != secondPointer->getValue()) {
            return false;
        } else {
            firstPointer = firstPointer->getNext();
            secondPointer = secondPointer->getNext();
        }
    }
    return (firstPointer == nullptr) && (secondPointer == nullptr);
}

List operator&(const List & first, const List & second) {
    List resultList;
    Elem* firstPointer =first.head_;
    Elem* secondPointer = second.head_;
    while (firstPointer != nullptr) {
        while(secondPointer != nullptr && secondPointer->getValue() < firstPointer->getValue()) {
            secondPointer = secondPointer->getNext();
        }
        if (secondPointer == nullptr) {
            return resultList;
        } else if (firstPointer->getValue() == secondPointer->getValue()) {
            resultList += firstPointer->getValue();
        }
        firstPointer = firstPointer->getNext();
    }
    return resultList;
}

List operator|(const List & first, const List & second) {
    List resultList;
    Elem* firstPointer =first.head_;
    Elem* secondPointer = second.head_;
    while (firstPointer != nullptr || secondPointer != nullptr) {
        if (firstPointer != nullptr && (secondPointer == nullptr || (firstPointer->getValue() < secondPointer->getValue()))) {
            resultList += firstPointer->getValue();
            firstPointer = firstPointer->getNext();
        } else {
            resultList += secondPointer->getValue();
            secondPointer = secondPointer->getNext();
        }
    }
    return resultList;
}

void List::merge(List & second) {
    Elem* firstPointer = head_;
    Elem* secondPointer = second.head_;
    if (secondPointer == nullptr) {
        return;
    } else if(firstPointer == nullptr) {
        head_ = second.head_;
        tail_ = second.tail_;
        second.head_ = nullptr;
        second.tail_ = nullptr;
        return;
    }
    if (firstPointer->getValue() > secondPointer->getValue()) {
        Elem* tmpPointer = secondPointer->getNext();
        secondPointer->setNext(firstPointer);
        head_ = secondPointer;
        firstPointer = secondPointer;
        secondPointer = tmpPointer;
    } else if (firstPointer->getValue() == secondPointer->getValue()) {
        secondPointer = secondPointer->getNext();
    }
    while (firstPointer != nullptr && secondPointer != nullptr) {
        while ((firstPointer->getNext() != nullptr) && (firstPointer->getNext()->getValue() < secondPointer->getValue())) {
            firstPointer = firstPointer->getNext();
        }
        if (first  Pointer->getNext() == nullptr) {
            firstPointer->setNext(secondPointer);
            tail_ = second.tail_;
            second.head_ = nullptr;
            second.tail_ = nullptr;
            return;
        } else if (firstPointer->getNext()->getValue() == secondPointer->getValue()) {
            secondPointer = secondPointer->getNext();
        } else {
            Elem* tmpPointer = secondPointer->getNext();
            secondPointer->setNext(firstPointer->getNext());
            firstPointer->setNext(secondPointer);
            firstPointer = secondPointer;
            secondPointer = tmpPointer;
        }
    }
    second.head_ = nullptr;
    second.tail_ = nullptr;
}



