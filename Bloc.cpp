#include "Bloc.h"
#include <iostream>
using namespace std;

Bloc::Bloc():Cladire(){
    etaj = 0;
    numarUsa = 0;
    nrInterfon = 0;
}

Bloc::Bloc(int AnCladire, double Pret, bool Chirie,
           int nrCamere,const vector<double> suprafata, const string Locuitor,std::string Oras,string Strada,int nrStrada, int etaj,
           int numarUsa, int nrInterfon):Cladire(AnCladire,Pret,Chirie,nrCamere,suprafata,Locuitor,Oras,Strada,nrStrada){
    this->etaj = etaj;
    this->numarUsa = numarUsa;
    this->nrInterfon = nrInterfon;

}
Bloc::Bloc(const Bloc &obj): Cladire(obj){
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

bool Bloc::operator==(const Bloc &rhs) const {
    for (int i = 0; i < nrCamere; i++) {
        if (suprafata[i] != rhs.suprafata[i])
            return false;
    }


    return nrCamere==rhs.nrCamere && idCladire==rhs.idCladire
           && AnCladire==rhs.AnCladire && Locuitor == rhs.Locuitor && Pret==rhs.Pret && Chirie==rhs.Chirie && rhs.adresa.getOras() == adresa.getOras() && rhs.adresa.getStrada() == adresa.getStrada() && rhs.adresa.getnrStrada() == adresa.getnrStrada()
           && etaj == rhs.etaj && nrInterfon == rhs.nrInterfon && numarUsa == rhs.numarUsa;

}

bool Bloc::operator!=(const Bloc &rhs) const {
    return !(*this==rhs);
}
int Bloc::getEtaj() const{
    return etaj;

}

void Bloc::setEtaj(int aux) {
    etaj = aux;
}

int Bloc::getNrInterfon() const {
    return nrInterfon;

}
void Bloc::setNrInterfon(int aux) {
    nrInterfon = aux;
}

int Bloc::getNumarUsa() const {
    return numarUsa;
}
void Bloc::setNumarUsa(int aux) {
    numarUsa = aux;
}