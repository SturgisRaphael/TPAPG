//
// Created by Raphael on 3/4/2018.
//
#include <array>
#include "service.h"
service::service(int numberOfSuppliers, int numberOfClients) : numberOfSuppliers(numberOfSuppliers),
                                                               numberOfClients(numberOfClients) {
    this->suppliers= static_cast<supplier *>(malloc(numberOfSuppliers * sizeof(supplier)));
}

service::~service() {
    free(suppliers);
}

int service::getNumberOfSuppliers() const {
    return numberOfSuppliers;
}

void service::setNumberOfSuppliers(int numberOfSuppliers) {
    service::numberOfSuppliers = numberOfSuppliers;
}

int service::getNumberOfClients() const {
    return numberOfClients;
}

void service::setNumberOfClients(int numberOfClients) {
    service::numberOfClients = numberOfClients;
}

const supplier *service::getSuppliers() const {
    return suppliers;
}

void service::setSupplier(int i, supplier supplier) {
    suppliers[i] = supplier;
}

std::ostream &operator<<(std::ostream &os, const service &service1) {
    os << "numberOfSuppliers: " << service1.numberOfSuppliers << " numberOfClients: " << service1.numberOfClients
       << " suppliers: [";

    for(int i = 0; i < service1.getNumberOfSuppliers() - 1; i++)
        os << service1.getSupplier(i) << ",";

    os << service1.getSupplier(service1.getNumberOfSuppliers() - 1) << "]";

    return os;
}

const supplier service::getSupplier(int i)const {
    return suppliers[i];
}

void service::openSupplier(int i) {
    suppliers[i].setOpen(true);
}

void service::closeSupplier(int i){
    suppliers[i].setOpen(false);
}

int service::evaluate(int *O, int size){
    int result = 0;

    for(int i = 0; i < size; i++){
        result += suppliers[O[i]].getOpeningCost();
        printf("%d, ", O[i]);
    }
    printf("\n");

    for(int j = 0; j < numberOfClients; j++){
        int min = suppliers[0].getConnexionCost(j);
        for(int i = 0; i < size; i++){
            if(min > suppliers[O[i]].getConnexionCost(j))
                min = suppliers[O[i]].getConnexionCost(j);
        }
        result += min;
    }


    return result;
}

int service::evaluate(){
    int result = 0;
    printf("numberOfSuppliers = %d\n", numberOfSuppliers);
    for(int i = 0; i < numberOfSuppliers; i++) {
        if(suppliers[i].isOpen())
            result += suppliers[i].getOpeningCost();
    }
    for(int j = 0; j < numberOfClients; j++)
    {
        int min = 1000000000;
        for(int k = 0; k < numberOfSuppliers; k++){
            if((min > suppliers[k].getConnexionCost(j)) && suppliers[k].isOpen())
                min = suppliers[k].getConnexionCost(j);
        }
        printf("min = %d\n", min);
        result += min;
    }

    return result;
}

void service::gloutonSolver() {
    closeAllSupplier();
    int optiEval = 0;
    for(int i = 0; i < numberOfSuppliers; i++) {
        openSupplier(i);
        if (optiEval > evaluate())
            closeSupplier(i);
    }
}

void service::closeAllSupplier() {
    for(int i = 0; i < numberOfSuppliers; i++)
        closeSupplier(i);
}

int *service::getO() {
    int count = 0;
    for(int i = 0; i < numberOfSuppliers; i++)
        if(suppliers[i].isOpen())
            count++;
    int O[count];

    count = 0;
    for(int i = 0; i < numberOfSuppliers; i++)
        if(suppliers[i].isOpen()){
            count++;
            O[count] = i;
        }

    return 0;
}


