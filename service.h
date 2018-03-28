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
#include <functional>

using namespace std;

class service {
public:
    class alpha{
        int value;
        int index;
        service &parent;
        vector<int> S;
    public:
        int getValue() const;
        int getIndex() const;

        alpha(service &parent, const vector<int> &S);
    };
    class beta{
        double value;
        int index;
        vector<int> Y;
        service *parent;
        vector<int> S;

    public:
        double getValue() const;

        int getIndex() const;

        const vector<int> &getY() const;

        beta(service *parent);

    public:
        beta(service *parent, vector<int> &S, int f);

        friend ostream &operator<<(ostream &os, const beta &beta);

        double betaCalc(int i, int f, vector<int> T, vector<int> &YTmp, bool changeIndex);
    };
    class stackElm{
        beta betaValue;
        int cValue;
        int ci;
        int cj;
        bool isBeta;
    public:

    public:
        stackElm(const beta &betaValue);

        beta getBetaValue();

        int getCValue() ;

        int getCi() ;

        int getCj() ;

        bool isIsBeta() ;

        stackElm(int cValue, int ci, int cj, service::beta betaValue);

    };

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

    void Algorithm2(int f);

    void Algorithme3(int f);

    vector<int> getO();

    void printO();

    void sort(vector<int> &S, int left, int right, int f);

private:
    int numberOfSuppliers;
    int numberOfClients;
    supplier* suppliers;

};

#endif //TPAPG_SERVICE_H