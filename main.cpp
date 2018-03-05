#include <iostream>
#include <fstream>
#include <sstream>
#include "supplier.h"
#include "service.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream input;
    input.open( "D:\\Raphael\\Programing\\Git\\TPAPG\\Test\\BildeKrarup\\B\\B1.1" );
    string line, nameOfService;
    int numberOfSuppliers, numberOfClients, id, costOpening, tmp;

    if (!input) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    getline( input, line );

    nameOfService = line.substr(line.find(": "));

    input >> numberOfSuppliers >> numberOfClients >> tmp;

    service service1(numberOfSuppliers, numberOfClients);

    getline( input, line );

    int costConnexions[numberOfClients];

    for( int i = 0; getline( input, line ); i++)
    {
        istringstream iss(line);
        iss >> id >> costOpening;
        for(int i = 0; iss; i++)
        {
            iss >> costConnexions[i];
        }

        supplier supplierI(id, costOpening, costConnexions);

        service1.setSupplier(i, supplierI);
    }

    service1.openSupplier(3);
    service1.openSupplier(1);
    service1.openSupplier(2);

    cout << service1.evaluate() << endl;

    return 0;
}