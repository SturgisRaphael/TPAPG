//
// Created by Raphael on 3/4/2018.
//

#ifndef TPAPG_SERVICE_H
#define TPAPG_SERVICE_H


#include <cstdlib>
#include <ostream>
#include "supplier.h"

class service {
public:
    service(int numberOfSuppliers, int numberOfClients);

    int getNumberOfSuppliers() const;

    void setNumberOfSuppliers(int numberOfSuppliers);

    int getNumberOfClients() const;

    void setNumberOfClients(int numberOfClients);

    const supplier *getSuppliers() const;

    void setSupplier(int i, supplier supplier);

    const supplier getSupplier(int i)const;

    void openSupplier(int i);

    friend std::ostream &operator<<(std::ostream &os, const service &service1);

    virtual ~service();

    int evaluate();

private:
    int numberOfSuppliers;
    int numberOfClients;
    supplier* suppliers;

    void closeSupplier(int i);
};

#endif //TPAPG_SERVICE_H