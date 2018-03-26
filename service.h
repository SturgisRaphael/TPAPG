//
// Created by Raphael on 3/4/2018.
//

#ifndef TPAPG_SERVICE_H
#define TPAPG_SERVICE_H


#include <cstdlib>
#include <ostream>
#include <array>
#include "supplier.h"
#include <vector>

using namespace std;

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

    int evaluate(int *O, int size);

    void closeAllSupplier();

    void closeSupplier(int i);

    void Algorithm1();

    void Algorithm2();

    int *getO();

    void printO();

private:
    int numberOfSuppliers;
    int numberOfClients;
    supplier* suppliers;

    double beta(int i, vector<int> S);

    double beta(int i, vector<int> S, vector<int> T);

    int beta(int i, vector<int> S, vector<int> T, vector<int> O);

    int beta(int i, vector<int> S, vector<int> T, vector<int> Y, vector<int> O);
};

#endif //TPAPG_SERVICE_H