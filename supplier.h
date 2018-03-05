//
// Created by Raphael on 3/4/2018.
//

#ifndef TPAPG_SUPPLIER_H
#define TPAPG_SUPPLIER_H


#include <ostream>

class supplier {
public:

    supplier(int id, int openingCost, int *connexionCost);

    int getId() const;

    void setId(int id);

    int getOpeningCost() const;

    void setOpeningCost(int openingCost);

    const int getConnexionCost(int i) const;

    bool isOpen() const;

    void setOpen(bool open);

    friend std::ostream &operator<<(std::ostream &os, const supplier &supplier1);

private:
    int id;
    int openingCost;
    int *connexionCost;
    bool open;
};

#endif //TPAPG_SUPPLIER_H

