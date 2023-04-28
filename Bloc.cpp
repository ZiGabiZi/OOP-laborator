#include "Bloc.h"
#include <iostream>
using namespace std;

Bloc::Bloc():Cladire(){
    etaj = 0;
    numarUsa = 0;
    nrInterfon = 0;
}

Bloc::Bloc(int AnCladire, double Pret, bool Chirie,
           int nrCamere,const std::vector<double> suprafata, const std::string Locuitor,std::string Oras,std::string Strada,int nrStrada, int etaj,
           int numarUsa, int nrInterfon):Cladire(AnCladire,Pret,Chirie,nrCamere,suprafata,Locuitor,Oras,Strada,nrStrada){
    this->etaj = etaj;
    this->numarUsa = numarUsa;
    this->nrInterfon = nrInterfon;

}
Bloc::Bloc(const Bloc &obj, const Adresa &obi): Cladire(obj, obi){
    etaj = obj.etaj;
    numarUsa = obj.numarUsa;
    nrInterfon = obj.nrInterfon;

}

Bloc& Bloc::operator =(const Bloc &obi){
    if(&obi != this){
        Cladire::operator=(obi);
        this->etaj = obi.etaj;
        this->numarUsa = obi.numarUsa;
        this->nrInterfon = obi.nrInterfon;




    }
    return *this;

}

Bloc::~Bloc() = default;

ostream& operator <<(ostream& out, const Bloc& c2){
    c2.Afisare(out);
    out << c2.getLocuitor() << " locuieste la etajul " << c2.etaj << " la usa cu numarul " << c2.numarUsa << " avand interfonul " << c2.nrInterfon<<endl;
    return out;
}

void Bloc::getTip() {
    cout << "Tipul este BLOC"<<endl;
}

istream& operator >>(istream& in, Bloc& c2){
    c2.Citire(in);
    cout << "Dati etajul: ";
    in >> c2.etaj;
    cout << "Dati numarul usii la care locuieste: ";
    in >> c2.numarUsa;
    cout << "Dati interfonul usii la care locuieste: ";
    in >> c2.nrInterfon;
    return in;
}