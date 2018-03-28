#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include "supplier.h"
#include "service.h"

using namespace std;

void affichage(string nameOfService, service service1){
    clock_t begin;
    clock_t end;
    cout << nameOfService << endl;
    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm1();

    end = clock();

    cout << "Algo1:(valeur,liste)=(" << service1.evaluate() << ",[";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "]) in " << double(end - begin)/ CLOCKS_PER_SEC << "sec" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm2(2);

    end = clock();

    cout << "Algo2-2*fi:(valeur,liste)=(" << service1.evaluate() << ",[";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "]) in " << double(end - begin)/ CLOCKS_PER_SEC << "sec" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm2(1);

    end = clock();

    cout << "Algo2-1*fi:(valeur,liste)=(" << service1.evaluate() << ",[";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "]) in " << double(end - begin)/ CLOCKS_PER_SEC << "sec" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithme3(2);

    end = clock();

    cout << "Algo3-2*fi:(valeur,liste)=(" << service1.evaluate() << ",[";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "]) in " << double(end - begin)/ CLOCKS_PER_SEC << "sec" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithme3(1);

    end = clock();

    cout << "Algo3-1*fi:(valeur,liste)=(" << service1.evaluate() << ",[";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "]) in " << double(end - begin)/ CLOCKS_PER_SEC << "sec" << endl;
}

int main(int argc, char* argv[]) {
    ifstream input;
    //input.open( "../Test/BildeKrarup/B/B1.1" );
    input.open("D:\\Raphael\\Programing\\Git\\TPAPG\\Test\\BildeKrarup\\B\\B1.1");
    //input.open( "../Test/test" );
    //input.open("D:\\Raphael\\Programing\\Git\\TPAPG\\Test\\test");
    string line, nameOfService;
    int numberOfSuppliers, numberOfClients, id, costOpening, tmp;

    if (!input) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    getline( input, line );

    nameOfService = line.substr(line.find(": ") + 2 );

    input >> numberOfSuppliers >> numberOfClients >> tmp;

    service service1(numberOfSuppliers, numberOfClients);

    getline( input, line );

    int *costConnexions;

    for( int i = 0; getline( input, line ); i++)
    {
        costConnexions = static_cast<int *>(malloc(numberOfClients * sizeof(int)));
        istringstream iss(line);
        iss >> id >> costOpening;
        for(int j = 0; iss; j++)
        {
            iss >> costConnexions[j];
        }

        supplier supplierI = supplier(id, costOpening, costConnexions);

        service1.setSupplier(i, supplier(id, costOpening, costConnexions));
    }
    affichage(nameOfService, service1);

    return 0;
}
