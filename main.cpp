#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "supplier.h"
#include "service.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream input;
    //input.open( "../Test/BildeKrarup/B/B1.1" );//D:\Raphael\Programing\Git\TPAPG
    input.open( "../Test/test" );
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
        for(int j = 0; iss; j++)
        {
            iss >> costConnexions[j];
        }

        supplier supplierI = supplier(id, costOpening, costConnexions);

        service1.setSupplier(i, supplier(id, costOpening, costConnexions));
    }

    /*
    service1.openSupplier(10);
    service1.openSupplier(13);
    service1.openSupplier(14);
    service1.openSupplier(32);
    service1.openSupplier(43);
*/
    service1.openSupplier(0);
    //service1.gloutonSolver();

    cout << service1.evaluate() << endl;

    return 0;
}