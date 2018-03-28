//
// Created by Raphael on 3/4/2018.
//
#include <array>
#include <iostream>
#include <cmath>
#include "service.h"
#include <vector>
#include <algorithm>

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

vector<int> service::getO() {
    int count = 0;
    for (int i = 0; i < numberOfSuppliers; i++)
        if (suppliers[i].isOpen())
            count++;
    vector<int> O;

    printf("count = %d\n", count);
    count = 0;
    for (int i = 0; i < numberOfSuppliers; i++)
        if (suppliers[i].isOpen()) {
            O.push_back(i);
            count++;
        }

    O.push_back(-1);

    return O;
}

void service::printO() {
    vector<int> O = getO();
    int i = 0;

    while (O[i] != -1) {
        printf("%d ", O[i]);
        i++;
    }
    printf("\n");
}
void service::Algorithm2() {
    closeAllSupplier();
    vector<int> S;
    vector<int> T;
    int nbUnaffectedClients = numberOfClients;

    for(int i = 0; i < numberOfClients; i++)
        S[i] = i;

    while(nbUnaffectedClients > 0){
        int alpha = INFINITY;
        int beta = INFINITY;
        vector<int> betaY;
        int alphaIndex = -1;
        int betaIndex = -1;
        double tmp;
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
                sort(S, 0, static_cast<int>(S.size()), i);

                tmp = betaConst(i,T, this->getO());
                double tmp2 = tmp;
                vector<int> Y;
                do{
                    if(!Y.empty())
                        tmp = static_cast<int>(tmp2 / Y.size());
                    Y.push_back(S[Y.size()]);
                    for(auto &j : Y)
                    {
                        tmp2 += this->getSupplier(i).getConnexionCost(j);
                    }
                }while(tmp2/Y.size() < tmp);

                if(tmp2 < beta){
                    betaIndex = i;
                    betaY = Y;
                }
            }
        }

        if(alpha <= beta)
        {
            for(int i = 0; i < S.size(); i++){
                if(S[i] == alphaIndex)
                {
                    S[i] = S.back();
                    S.pop_back();
                }
            }
        }
        else
        {
            for(int i = 0; i < S.size(); i++){
                for(auto &y : betaY)
                {
                    if(S[i] == y)
                    {
                        S[i] = S.back();
                        S.pop_back();
                    }
                }
            }
            this->openSupplier(betaIndex);
        }
    }


}

double service::betaConst(int i, vector<int> T, vector<int> O) {
    double result = 2 * this->suppliers[i].getOpeningCost();
    int min = INFINITY;
    for(auto &j : T){
        for(auto &o : O){
            if(min < this->suppliers[o].getConnexionCost(j))
                min = this->suppliers[o].getConnexionCost(j);
        }
        if(min > 0)
            result -= (min - this->suppliers[i].getConnexionCost(j));
    }
}

void service::sort(vector<int> S, int left, int right, int f) {
    int i = left, j = right;
    int tmp;
    int pivot = this->getSupplier(f).getConnexionCost(S[(left + right) / 2]);

    /* partition */
    while (i <= j) {
        while (this->getSupplier(f).getConnexionCost(S[i]) < pivot)
            i++;
        while (this->getSupplier(f).getConnexionCost(S[j]) > pivot)
            j--;
        if (i <= j) {
            tmp = S[i];
            S[i] = S[j];
            S[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        sort(S, left, j, f);
    if (i < right)
        sort(S, i, right, f);
}





