#include <iostream>
#include "List.h"

int main() {
    List list;
    list += 3;
    list += 5;
    list += 100;
    list += 12;
    list += 41;
    list += 1;
    list += 2;
    list += 2;
    list.print();
    return 0;
}
