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
    }

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
    vector<int> O;

    for (int i = 0; i < numberOfSuppliers; i++)
        if (suppliers[i].isOpen()) {
            O.push_back(i);
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
void service::Algorithm2(int f) {
    closeAllSupplier();
    vector<int> S;
    vector<int> T;

    for(int i = 0; i < numberOfClients; i++)
        S.push_back(i);

    while(S.size() > 0){
        service::alpha alpha = service::alpha(*this, S);
        service::beta beta = service::beta(this, S, f, true);
        //cout << "alpha = " << alpha.getValue() << "|beta = " << beta.getValue() << endl;
        if(alpha.getValue() <= beta.getValue()){
            for(int s = 0; s < S.size(); s++)
            {
                if(S[s] == alpha.getIndex())
                {
                    S[s] = S.back();
                    S.pop_back();
                    break;
                }
            }
        } else{
            for(int s = 0; s < S.size(); s++)
            {
                for(auto &y : beta.getY())
                    if(S[s] == y)
                    {
                        S[s] = S.back();
                        S.pop_back();
                    }
            }
            this->openSupplier(beta.getIndex());
        }
    }
}

void service::sort(vector<int> &S, int left, int right, int f) {
    if(left > right)
        return;
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


int service::alpha::getValue() const {
    return value;
}

int service::alpha::getIndex() const {
    return index;
}

service::alpha::alpha(service &parent, const vector<int> &S) : parent(parent), S(S) {
    value = INFINITY;
    index = -1;
    for(int i = 0; i < parent.getNumberOfSuppliers(); i++)
    {
        if(parent.getSupplier(i).isOpen()){
            for(auto &j : S){
                if(value > parent.getSupplier(i).getConnexionCost(j)){
                    value = parent.getSupplier(i).getConnexionCost(j);
                    index = j;
                }
            }
        }
    }
}

service::beta::beta(service *parent, vector<int> &S, int f, bool calc) : parent(parent), S(S) {
    if(calc)
    {
        value = INFINITY;
        index = -1;
        vector<int> T;
        for(int o = 0; o < parent->getNumberOfClients(); o++)
        {
            bool in = false;
            for(int s : S){
                if(s == o)
                    in = true;
            }
            if(!in)
                T.push_back(o);
        }
        for(int i = 0; i < parent->getNumberOfSuppliers(); i++)
        {
            vector<int> YTmp;
            if(!parent->getSupplier(i).isOpen()){
                double valueTmp = betaCalc(i, f, T, YTmp, false);
                if(valueTmp < value)
                {
                    value = valueTmp;
                    index = i;
                    YTmp.pop_back();
                    Y = YTmp;
                }
            }
        }
    }
}

double service::beta::getValue() const {
    return value;
}

int service::beta::getIndex() const {
    return index;
}

const vector<int> &service::beta::getY() const {
    return Y;
}

ostream &operator<<(ostream &os, const service::beta &beta) {
    os << "value: " << beta.value << " index: " << beta.index << " Y:{";
    for(auto &y : beta.Y)
       os << y << ", ";
    os << "}";
    return os;
}

double service::beta::betaCalc(int i, int f, vector<int> T, vector<int> &YTmp, bool staticMode) {
    if(staticMode)
        this->index = i;
    double valueTmp = f * (parent->getSupplier(i).getOpeningCost());
    int sum = 0;
    for(int &j : T){
        int min = INFINITY;
        for(int m = 0; m < parent->getNumberOfSuppliers(); m++)
        {
            if(parent->getSupplier(m).isOpen()){
                if(parent->getSupplier(m).getConnexionCost(j) < min){
                    min = parent->getSupplier(m).getConnexionCost(j);
                }
            }
        }
        if(min == INFINITY)
            min = 0;
        if(min - parent->getSupplier(i).getConnexionCost(j) > 0)
        {
            sum += min - parent->getSupplier(i).getConnexionCost(j);
        }
    }
    valueTmp -= sum;
    parent->sort(S, 0, S.size() - 1, i);
    double pred_value = INFINITY, val = 0;
    for (int r : S) {
        val = valueTmp;
        YTmp.push_back(r);
        for(auto &y : YTmp){
            val += parent->getSupplier(i).getConnexionCost(y);
        }
        if(pred_value < val/YTmp.size()){
            break;
        } else
        {
            pred_value = val/YTmp.size();
        }
    }
    valueTmp = pred_value;
    if(staticMode){
        this->value = valueTmp;
        this->Y = YTmp;
    }
    //cout << valueTmp << endl;
    return valueTmp;
}

service::beta::beta(service *parent) : parent(parent) {}

void service::Algorithme3(int f) {
    closeAllSupplier();
    vector<int> S;
    vector<int> S_bis;
    vector<stackElm> T;

    for(int i = 0; i < numberOfClients; i++)
        S.push_back(i);

    for(int i = 0; i < numberOfSuppliers; i++)
    {
        vector<int> tmp;
        beta tmpB = service::beta(this, S, f, false);
        tmpB.betaCalc(i, f, S_bis, tmp, true);
        T.push_back(stackElm(tmpB));
    }

    while(!T.empty()){
        stackElm x = T.back();
        double valMin;
        if (x.isIsBeta())
            valMin = x.getBetaValue().getValue();
        else
            valMin = x.getCValue();
        int indT = 0;
        for(int t = 0; t < T.size(); t++) {
            if (T[t].isIsBeta()) {
                if((T[t].getBetaValue().getValue() < valMin))
                {
                    valMin = T[t].getBetaValue().getValue();
                    x = T[t];
                    indT = t;
                }
            }
            else
            {
                if((T[t].getCValue() < valMin))
                {
                    valMin = T[t].getCValue();
                    x = T[t];
                    indT = t;
                }
            }

        }
        x = T[indT];
        T[indT] = T.back();
        T.pop_back();
        if(x.isIsBeta() && !S.empty())
        {
            vector<int> tmp;
            beta tmpB = service::beta(this,S,f, false);
            tmpB.betaCalc(x.getBetaValue().getIndex(), f, S_bis, tmp, true);
            if(x.getBetaValue().getValue() == tmpB.getValue()){
                this->openSupplier(x.getBetaValue().getIndex());
                for(int i = 0; i < S.size(); i++)
                {
                    for(int j : x.getBetaValue().getY()){
                        if(S[i] == j){
                            S_bis.push_back(S[i]);
                            S[i] = S.back();
                            S.pop_back();
                            break;
                        }
                    }
                }
                for(int j : S)
                    T.emplace_back(stackElm(this->getSupplier(x.getBetaValue().getIndex()).getConnexionCost(j),x.getBetaValue().getIndex(), j, tmpB));
            } else
            {
                T.emplace_back(tmpB);
            }
        } else{
            for(int s = 0; s < S.size(); s++)
            {
                if(S[s] == x.getCj())
                {
                    S_bis.push_back(S[s]);
                    S[s] = S.back();
                    S.pop_back();
                    break;
                }
            }
        }
    }
}

service::stackElm::stackElm(const service::beta &betaValue) : betaValue(betaValue) {isBeta = true;}

service::stackElm::stackElm(int cValue, int ci, int cj, service::beta betaValue)
        : cValue(cValue), ci(ci), cj(cj), betaValue(betaValue) { isBeta = false;}

service::beta service::stackElm::getBetaValue(){
    return betaValue;
}

int service::stackElm::getCValue()  {
    return cValue;
}

int service::stackElm::getCi()  {
    return ci;
}

int service::stackElm::getCj()  {
    return cj;
}

bool service::stackElm::isIsBeta()  {
    return isBeta;
}

