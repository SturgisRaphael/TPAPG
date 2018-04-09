#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstring>
#include "supplier.h"
#include "service.h"

void affichageXML(string basic_string, service service, int optimum);

void affichageSimple(string nameOfService, service service1, int opti);

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
    ifstream input, opt;
    //input.open( "../Test/BildeKrarup/B/B1.1" );
    //input.open("D:\\Raphael\\Programing\\Git\\TPAPG\\Test\\BildeKrarup\\B\\B1.1");
    //input.open( "../Test/test" );
    //input.open("D:\\Raphael\\Programing\\Git\\TPAPG\\Test\\test");

    input.open(argv[1]);
    opt.open(strcat(argv[1], ".opt"));

    if(!opt){
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string line, nameOfService, line2;
    int numberOfSuppliers, numberOfClients, id, costOpening, tmp;

    if (!input) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    getline( opt, line2 );

    istringstream iss(line2);
    int opti = 0, next = 0;
    while(iss)
    {
        opti = next;
        iss >> next;
    }

    getline( input, line );

    nameOfService = argv[1];

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
    //affichage(nameOfService, service1);

    //affichageXML(nameOfService, service1, opti);

    affichageSimple(nameOfService, service1, opti);

    return 0;
}

void affichageSimple(string nameOfService, service service1, int opti) {
    clock_t begin;
    clock_t end;
    cout  << nameOfService << "," << opti;
    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm1();

    end = clock();

    cout << ", " << service1.evaluate() << ", "<< double(end - begin)/ CLOCKS_PER_SEC;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm2(2);

    end = clock();

    cout << ", " << service1.evaluate() << ", "<< double(end - begin)/ CLOCKS_PER_SEC;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm2(1);

    end = clock();

    cout << ", " << service1.evaluate() << ", "<< double(end - begin)/ CLOCKS_PER_SEC;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithme3(2);

    end = clock();

    cout << ", " << service1.evaluate() << ", "<< double(end - begin)/ CLOCKS_PER_SEC;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithme3(1);

    end = clock();

    cout << "," << service1.evaluate() << ", " << double(end - begin)/ CLOCKS_PER_SEC << endl;
}

void affichageXML(string nameOfService, service service1, int optimum) {
    clock_t begin;
    clock_t end;
    cout << "<service name='" << nameOfService << "'>\n<optimum>" << optimum << "</optimum>" << endl;
    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm1();

    end = clock();

    cout << "<Algo1>\n<value>" << service1.evaluate() << "</value>\n<solution>";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "</solution>\n<time>" << double(end - begin)/ CLOCKS_PER_SEC << "</time>" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm2(2);

    end = clock();

    cout << "<Algo2 f='2'>\n<value>" << service1.evaluate() << "</value>\n<solution>";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "</solution>\n<time>" << double(end - begin)/ CLOCKS_PER_SEC << "</time>" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithm2(1);

    end = clock();

    cout << "<Algo2 f='1'>\n<value>" << service1.evaluate() << "</value>\n<solution>";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "</solution>\n<time>" << double(end - begin)/ CLOCKS_PER_SEC << "</time>" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithme3(2);

    end = clock();

    cout << "<Algo3 f='2'>\n<value>" << service1.evaluate() << "</value>\n<solution>";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "</solution>\n<time>" << double(end - begin)/ CLOCKS_PER_SEC << "</time>" << endl;

    service1.closeAllSupplier();

    begin = clock();

    service1.Algorithme3(1);

    end = clock();

    cout << "<Algo3 f='1'>\n<value>" << service1.evaluate() << "</value>\n<solution>";
    for(int i : service1.getO()){
        if(i != -1)
            cout << service1.getSupplier(i).getId();
        else
            break;
        cout << ",";
    }
    cout << "</solution>\n<time>" << double(end - begin)/ CLOCKS_PER_SEC << "</time>" << endl;

    cout << "</service>" << endl;
}

