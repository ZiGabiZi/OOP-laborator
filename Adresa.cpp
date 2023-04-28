#include "Adresa.h"
#include <iostream>
using namespace std;

Adresa::Adresa() {
    Oras = "Necunoscut";
    Strada = "Necunoscută";
    nrStrada = 0;

}

Adresa::Adresa(std::string Oras, std::string Strada, int nrStrada) {
    this->Oras = Oras;
    this->Strada = Strada;
    this->nrStrada = nrStrada;

}

Adresa::Adresa(const Adresa &obj) {
    this->Oras = obj.Oras;
    this->Strada = obj.Strada;
    this->nrStrada = obj.nrStrada;

}

void Adresa::afis() {
    cout << "Locuieste in orasul " << Oras << ", pe strada " << Strada << " la numarul " << nrStrada;
}


Adresa& Adresa::operator=(const Adresa &obj) {
    if(this!=&obj){
        this->Oras = obj.Oras;
        this->Strada = obj.Strada;
        this->nrStrada = obj.nrStrada;
    }

    return *this;
}

ostream& operator <<(ostream& out, const Adresa& c1){
    out << "Locuieste in orasul " << c1.Oras << ", pe strada " << c1.Strada << " la numarul " << c1.nrStrada;

    return out;

}

istream& operator >> (istream& in, Adresa& c1){
    cout << "Dati orasul in care locuieste: ";
    in.get();
    getline(in, c1.Oras);

    cout <<"Dati strada pe care locuieste: ";
    in.get();
    getline(in, c1.Strada);

    cout << "Dati numarul strazii pe care locuieste: ";
    in >> c1.nrStrada;

    return in;
}

const string Adresa::getOras() const {
    return Oras;
}

const string Adresa::getStrada() const {
    return Strada;
}

int Adresa::getnrStrada() const {
    return nrStrada;
}

void Adresa::setOras(const string ORAS) {
    this->Oras = ORAS;

}

void Adresa::setStrada(const string STRADA) {

    Strada = STRADA;
}

void Adresa::setnrStrada(const int NRSTRADA) {
    this->nrStrada = NRSTRADA;
}