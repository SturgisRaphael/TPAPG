#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "supplier.h"
#include "service.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream input;
    //input.open( "../Test/BildeKrarup/B/B1.1" );
    input.open("D:\\Raphael\\Programing\\Git\\TPAPG\\Test\\BildeKrarup\\B\\B1.2");
    //input.open( "../Test/test" );
    //input.open("D:\\Raphael\\Programing\\Git\\TPAPG\\Test\\test");
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

    service1.Algorithm1();

    service1.printO();

    cout << "evaluate: " << service1.evaluate() << endl;

    return 0;
}