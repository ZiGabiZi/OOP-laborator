#include "Cladire.h"
#include <iostream>
#include <cstring>
using namespace std;

int Cladire::contorCladire = 0;
Cladire::Cladire():idCladire(contorCladire++) {
    AnCladire = 0;
    nrCamere = 0;

    Pret = 0.0;
    Chirie = true;

    Locuitor = "Anonim";


}

Cladire::Cladire(int AnCladire, double Pret, bool Chirie,
                 int nrCamere,const std::vector<double> Suprafata, const std::string Locuitor):idCladire(contorCladire++) {

    this->AnCladire = AnCladire;
    this->Pret = Pret;
    this->Chirie = Chirie;
    this->nrCamere = nrCamere;


    for(auto element:Suprafata) {
        this->suprafata.push_back(element);
    }

    this->Locuitor=Locuitor;
}



Cladire::Cladire(const Cladire &obj):idCladire(contorCladire++){
    this->AnCladire = obj.AnCladire;
    this->Pret = obj.Pret;
    this->Chirie = obj.Chirie;
    this->nrCamere = obj.nrCamere;
    this->suprafata = obj.suprafata;
    this->Locuitor = obj.Locuitor;


}


Cladire::~Cladire() = default;



ostream& operator <<(ostream& out, const Cladire& c1){
    out << "ID Cladire este: " <<  c1.idCladire - 999  << endl;
    out << "Nr camere: " << c1.nrCamere << endl;
    for (int i = 0; i<c1.nrCamere; i++){
        out << "Suprafata camerei " << i+1 << " este de " << c1.suprafata[i] << " metri patrati" << endl;
    }
    out << "Cladirea a fost fabricata in anul: " << c1.AnCladire << endl;
    out << "In cladire locuieste " << c1.Locuitor << endl;
    if(c1.Chirie == 1)
        out << c1.Locuitor << " plateste " << c1.Pret << " ron lunar" << endl;
    else
        out << c1.Locuitor << " a cumparat casa cu " << c1.Pret << " ron"<< endl;

    return out;


}



istream& operator >> (istream& in, Cladire& c1){
    cout << "Dati nr camere: ";
    in >> c1.nrCamere;


    std::vector<double> sp;

    for(int i=0; i<c1.nrCamere;i++){
        double aux;
        cout<< "Dati suprafata camerei " << i+1 << ": ";
        in >> aux;
        sp.push_back(aux);
    }
    c1.setSuprafata(sp);

    cout << "Dati anul in care a fost construita cladirea: ";
    in >> c1.AnCladire;

    cout << "Dati numele locuitorului: ";
    string aux;
    in >> aux;
    c1.setLocuitor(aux);

    cout << "Doriti ca locuitorul sa stea cu chirie? Apasati 1 pentru DA, sau 0 pentru NU :";
    in >> c1.Chirie;

    if(c1.Chirie == 1) {
        cout << "Dati pretul pe care doriti ca locuitorul sa-l plateasca lunar: ";
        in >> c1.Pret;
    }
    else{
        cout << "Dati suma pe care a platito locuitorul pentru casa: ";
        in >> c1.Pret;

    }

    return in;

}


double Cladire::getPret() const{
    return Pret;
}
void Cladire::setPret(double aux){
    this->Pret = aux;
}
bool Cladire::getChirie() const{
    return Chirie;
}
void Cladire::setChirie(bool aux){
    this->Chirie = aux;
}
int Cladire::getAnCladire() const{
    return AnCladire;
}
void Cladire::setAnCladire(int aux){
    this->AnCladire = aux;
}
int Cladire::getnrCamere() const {
    return nrCamere;
}
void Cladire::setnrCamere(int aux){
    this->nrCamere = aux;
}

int Cladire::getidCladire() const {
    return idCladire;
}
void Cladire::setidCladire(const int aux){
    this->idCladire = aux;
}


int Cladire::getcontorCladire() {
    return Cladire::contorCladire;
}


void Cladire::setcontorCladire(const int aux){
    Cladire::contorCladire = aux;
}




const std::vector<double> Cladire::getsuprafata()const{
    return this->suprafata;
}

void Cladire::setSuprafata(const std::vector<double>Suprafata){
    this->suprafata.clear();
    for(auto element:Suprafata)
        suprafata.push_back(element);

}


const string Cladire::getLocuitor() const{
    return Locuitor;

}

void Cladire::setLocuitor(const string nume){
    this->Locuitor = nume;

}

bool Cladire::operator==(const Cladire &rhs) const{
    for (int i = 0; i < nrCamere; i++) {
        if (suprafata[i] != rhs.suprafata[i])
            return false;
    }

    return nrCamere==rhs.nrCamere && idCladire==rhs.idCladire
           && AnCladire==rhs.AnCladire && Locuitor == rhs.Locuitor && Pret==rhs.Pret && Chirie==rhs.Chirie;
}

bool Cladire::operator!=(const Cladire &rhs) const{
    return !(*this==rhs);
}


Cladire& Cladire::operator =(const Cladire &obj){
    if(this!= &obj)
    {


        this->AnCladire = obj.AnCladire;
        this->Pret = obj.Pret;
        this->Chirie = obj.Chirie;
        this->nrCamere = obj.nrCamere;
        this->suprafata = obj.suprafata;

        this->Locuitor=obj.Locuitor;
        Cladire::idCladire = obj.idCladire;
//        Cladire::contorCladire = obj.contorCladire; //////

    }
    return *this;


}




