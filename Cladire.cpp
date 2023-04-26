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

    suprafata = nullptr;
    Locuitor = new char [7]; ///
    strcpy(Locuitor, "ANONIM");


}

Cladire::Cladire(int AnCladire, double Pret, bool Chirie,
                 int nrCamere,const double* suprafata, const char* Locuitor):idCladire(contorCladire++) {

    this->AnCladire = AnCladire;
    this->Pret = Pret;
    this->Chirie = Chirie;
    this->nrCamere = nrCamere;

    this->suprafata = new double[nrCamere];
    for (int i = 0; i < nrCamere; i++) {
        this->suprafata[i] = suprafata[i];
    }

    this->Locuitor = new char[strlen(Locuitor) + 1];
    strcpy(this->Locuitor, Locuitor);
}



Cladire::Cladire(const Cladire &obj):idCladire(contorCladire++){
    this->AnCladire = obj.AnCladire;
    this->Pret = obj.Pret;
    this->Chirie = obj.Chirie;
    this->nrCamere = obj.nrCamere;
    this->suprafata = new double [obj.nrCamere];
    for(int i=0; i<nrCamere;i++){
        this->suprafata[i] = obj.suprafata[i];
    }

    this->Locuitor = new char [strlen(obj.Locuitor) +1];
    strcpy(this->Locuitor, obj.Locuitor);


}


Cladire::~Cladire(){

    delete[] this->suprafata;
    suprafata = nullptr;

    delete[] this->Locuitor;
    Locuitor = nullptr;

}

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


    double *sp = new double [c1.nrCamere]; ///
    for(int i=0; i<c1.nrCamere;i++){
        cout<< "Dati suprafata camerei " << i+1 << ": ";
        in >> sp[i];
    }
    c1.setSuprafata(sp, c1.nrCamere);
    delete[] sp;

    cout << "Dati anul in care a fost construita cladirea: ";
    in >> c1.AnCladire;

    cout << "Dati numele locuitorului: ";
    char aux[20];
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




const double* Cladire::getsuprafata()const{
    return this->suprafata;
}

void Cladire::setSuprafata(const double *Suprafata, int n){
    double *sp = new double[n];
    for(int i = 0; i < n; i ++)
        sp[i] = Suprafata[i];
    delete[] this->suprafata;
    Cladire::suprafata = sp;
}


const char* Cladire::getLocuitor() const{
    return Locuitor;

}

void Cladire::setLocuitor(const char* nume){
    if(this->Locuitor!= nullptr){
        delete[] this->Locuitor;
        this->Locuitor = nullptr;
    }
    int len = strlen(nume)+1;
    this->Locuitor = new char[len];
    strcpy(this->Locuitor, nume);

}

bool Cladire::operator==(const Cladire &rhs) const{
    for (int i = 0; i < nrCamere; i++) {
        if (suprafata[i] != rhs.suprafata[i])
            return false;
    }

    return nrCamere==rhs.nrCamere && idCladire==rhs.idCladire
           && AnCladire==rhs.AnCladire && strcmp(Locuitor,rhs.Locuitor)==0 && Pret==rhs.Pret && Chirie==rhs.Chirie;
}

bool Cladire::operator!=(const Cladire &rhs) const{
    return !(*this==rhs);
}


Cladire& Cladire::operator =(const Cladire &obj){
    if(this!= &obj)
    {

        delete[] this->suprafata;

        this->AnCladire = obj.AnCladire;
        this->Pret = obj.Pret;
        this->Chirie = obj.Chirie;
        this->nrCamere = obj.nrCamere;
        this->suprafata = new double [obj.nrCamere];
        for(int i=0; i<nrCamere;i++){
            this->suprafata[i] = obj.suprafata[i];
        }
        delete[] this->Locuitor;
        this->Locuitor = new char [strlen(obj.Locuitor) +1]; ///
        strcpy(this->Locuitor, obj.Locuitor);
        Cladire::idCladire = obj.idCladire;
//        Cladire::contorCladire = obj.contorCladire; //////

    }
    return *this;


}




