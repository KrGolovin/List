//
// Created by Macbook Pro on 06/02/2020.
//

#ifndef UNTITLED5_LIST_H
#define UNTITLED5_LIST_H

#include <iostream>
#include "Elem.h"
class List {
public:
    List();
    List(List &&);
    ~List();
    void operator+=(int);
    bool operator==(const List &) const;
    void merge(List &);
    friend std::ostream& operator<< (std::ostream &, const List &);
    friend List operator&(const List&, const List &);
    friend List operator|(const List&, const List &);

private:
    Elem* head_;
    Elem* tail_;
};
#endif //UNTITLED5_LIST_H
