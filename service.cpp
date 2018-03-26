//
// Created by Raphael on 3/4/2018.
//
#include <array>
#include <iostream>
#include <cmath>
#include "service.h"
#include <vector>
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
    os << "numberOfSuppliers: " << service1.numberOfSuppliers << "\n numberOfClients: " << service1.numberOfClients
       << "\nsuppliers: [";

    for(int i = 0; i < service1.getNumberOfSuppliers(); i++)
    {
        os << service1.getSupplier(i) << " client connexion cost [";
        for(int j = 0; j < service1.getNumberOfClients(); j++)
        {
            os << service1.getSupplier(i).getConnexionCost(j) << ",";
        }
        os << "]\n\t";
    }


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
        //printf("%d, ", O[i]);
    }
    //printf("\n");

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
    //printf("numberOfSuppliers = %d\n", numberOfSuppliers);
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
        //printf("min = %d\n", min);
        result += min;
    }

    return result;
}

void service::Algorithm1() {
    closeAllSupplier();
    int optiEval = INFINITY;
    bool flag = true;
    while (flag) {
        int optiIndex = -1;
        flag = false;
        for (int i = 0; i < numberOfSuppliers; i++) {
            if (!getSupplier(i).isOpen()) {
                openSupplier(i);
                if (optiEval > evaluate()) {
                    optiEval = evaluate();
                    optiIndex = i;
                }
                closeSupplier(i);
            }
        }
        if (optiIndex != -1) {
            openSupplier(optiIndex);
            flag = true;
        }
    }
}


void service::closeAllSupplier() {
    for (int i = 0; i < numberOfSuppliers; i++)
        closeSupplier(i);
}

int *service::getO() {
    int count = 0;
    for (int i = 0; i < numberOfSuppliers; i++)
        if (suppliers[i].isOpen())
            count++;
    int *O = static_cast<int *>(malloc(sizeof(int) * (count + 1)));

    printf("count = %d\n", count);
    count = 0;
    for (int i = 0; i < numberOfSuppliers; i++)
        if (suppliers[i].isOpen()) {
            O[count] = i;
            count++;
        }

    O[count] = -1;

    return O;
}

void service::printO() {
    int *O = getO();
    int i = 0;

    while (O[i] != -1) {
        printf("%d ", O[i]);
        i++;
    }
    printf("\n");
    free(O);
}
void service::Algorithm2() {
    closeAllSupplier();
    vector<int> S;
    int nbUnaffectedClients = numberOfClients;

    for(int i = 0; i < numberOfClients; i++)
        S[i] = i;

    while(nbUnaffectedClients > 0){
        int alpha = INFINITY;
        int beta = INFINITY;
        int alphaIndex = -1;
        int betaIndex = -1;
        for(int i = 0; i < numberOfSuppliers; i++){
            if(suppliers[i].isOpen()){
                for(int j = 0; j < numberOfClients; j++){
                    if(S[i] != -1){
                        if(alpha < suppliers[i].getConnexionCost(j)){
                            alpha = suppliers[i].getConnexionCost(j);
                            alphaIndex = j;
                        }
                    }
                }
            }
            else{

            }
        }
        betaIndex = alphaIndex + 1;

    }


}

int service::beta(int i, vector<int> S, vector<int> T, vector<int> Y, vector<int> O) {
    int result = 2 * this->suppliers[i].getOpeningCost();
    int min = INFINITY;
    for(auto &j : T){
        for(auto &o : O){
            if(min < this->suppliers[o].getConnexionCost(j))
                min = this->suppliers[o].getConnexionCost(j);
        }
        result -= (min - this->suppliers[i].getConnexionCost(j));
    }

    for(auto &j : Y){
        result += this->suppliers[i].getConnexionCost(j);
    }
    return result/Y.size();
}



