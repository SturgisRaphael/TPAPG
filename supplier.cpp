//
// Created by Raphael on 3/4/2018.
//

#include "supplier.h"

supplier::supplier(int id, int openingCost, int *connexionCost) : id(id), openingCost(openingCost),
                                                                  connexionCost(connexionCost) {open = false;}

int supplier::getId() const {
    return id;
}

void supplier::setId(int id) {
    supplier::id = id;
}

int supplier::getOpeningCost() const {
    return openingCost;
}

void supplier::setOpeningCost(int openingCost) {
    supplier::openingCost = openingCost;
}

std::ostream &operator<<(std::ostream &os, const supplier &supplier1) {
    os << "id: " << supplier1.id << " openingCost: " << supplier1.openingCost;
    return os;
}

bool supplier::isOpen() const {
    return open;
}

void supplier::setOpen(bool open) {
    supplier::open = open;
}

const int supplier::getConnexionCost(int i) const {
    return connexionCost[i];
}
