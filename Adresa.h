#include <iostream>

#ifndef OOP_ADRESA_H
#define OOP_ADRESA_H
using namespace std;
class Adresa{
    string Oras;
    string Strada;
    string Bloc;
    int etaj;
    int Camera;
public:
    Adresa();
    Adresa(string Oras, string Strada, string Bloc, int etaj, int Camera);



};


#endif //OOP_ADRESA_H
