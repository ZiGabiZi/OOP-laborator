#include "Casa.h"
#include <iostream>
#include <vector>

using namespace std;

Casa::Casa():Cladire() {
    Suprafata_Curte = 0;
    etaje = 0;
    ANIMALE = false;
}

Casa::Casa(int AnCladire, double Pret, bool Chirie,
           int nrCamere,const vector<double> suprafata, const string Locuitor,string Oras,string Strada,int nrStrada,
           double Suprafata_Curte, int etaje, bool ANIMALE,const vector<string> Animale):Cladire(AnCladire,Pret,Chirie,nrCamere,suprafata,Locuitor,Oras,Strada,nrStrada){
    this->Suprafata_Curte = Suprafata_Curte;
    this->etaje = etaje;
    this->ANIMALE = ANIMALE;
    for(auto element:Animale){
        this->Animale.push_back(element);
    }

}

Casa::Casa(const Casa &obj, const Adresa &obi): Cladire(obj, obi){
    Suprafata_Curte = obj.Suprafata_Curte;
    etaje = obj.etaje;
    ANIMALE = obj.ANIMALE;
    Animale.clear();
    for(auto element:obj.Animale){
        Animale.push_back(element);
    }

}

Casa &Casa::operator=(const Casa &obi) {
    if(&obi != this){
        Cladire::operator=(obi);
        this->Suprafata_Curte = obi.Suprafata_Curte;
        this->etaje = obi.etaje;
        this->ANIMALE = obi.ANIMALE;
        Animale.clear();
        for(auto element:obi.Animale){
            Animale.push_back(element);
        }
    }
    return *this;

}

Casa::~Casa() = default;

ostream& operator <<(ostream& out, const Casa& c2){
    c2.Afisare(out);
    out << c2.getLocuitor() << " sta la casa si are o curte cu o suprafata de " << c2.Suprafata_Curte << " metri patrati";
    out << c2.getLocuitor() << " are o casa cu " << c2.etaje << " etaj/e ";
    if(c2.ANIMALE == true){
        out << c2.getLocuitor() << " are animale, acestea fiind: ";
        for(auto element:c2.Animale){
            out << element << " ";
        }
        out << endl;

    }
    else{
        out << c2.getLocuitor() << " nu are nici un animal :(";
    }
    return out;
}


istream& operator >> (istream& in, Casa& c2){
    c2.Citire(in);
    cout<< "Dati suprafata curtii lui " << c2.getLocuitor() << ": ";
    double aux;
    in >> aux;
    c2.setSuprafata_Curte(aux);
    cout << "Spuneti cate etaje doriti sa aiba casa lui "<< c2.getLocuitor()<< ": ";
    int aux2;
    in >> aux2;
    c2.setEtaje(aux2);
    cout << "Doriti ca " << c2.getLocuitor()<< " sa aiba animale la casa? Scrieti 1 sau 0";
    int aux3;
    in >> aux3;
    if(aux3 == 1){
        c2.setANIMALE(true);
        c2.Animale.clear();
        int x;
        cout << "Cate animale doriti sa aiba?";
        in >> x;
        cout << "Enumerati tipurile de animale pe care sa le aiba si 0 dupa ce le-ati enumerat pe toate: ";
        for (int i=0;i<x;i++){
            string s;
            getline(in, s);
            c2.Animale.push_back(s);
            in.get();
        }



    }
    else{
        c2.setANIMALE(false);
    }



    return in;

}


void Casa::getTip() {
    cout << "Tipul obiectului este casa";
}

bool Casa::operator==(const Casa &rhs) const {
    for (int i = 0; i < nrCamere; i++) {
        if (suprafata[i] != rhs.suprafata[i])
            return false;
    }


    return nrCamere==rhs.nrCamere && idCladire==rhs.idCladire
           && AnCladire==rhs.AnCladire && Locuitor == rhs.Locuitor && Pret==rhs.Pret && Chirie==rhs.Chirie && rhs.adresa.getOras() == adresa.getOras() && rhs.adresa.getStrada() == adresa.getStrada() && rhs.adresa.getnrStrada() == adresa.getnrStrada()
           && Suprafata_Curte == rhs.Suprafata_Curte && etaje == rhs.etaje && ANIMALE == rhs.ANIMALE && Animale == rhs.Animale;

}

bool Casa::operator!=(const Casa &rhs) const {
    return !(*this==rhs);
}

int Casa::getEtaje() const{
    return etaje;

}
void Casa::setEtaje(int aux) {
    etaje = aux;
}
double Casa::getSuprafata_Curte() const {
    return Suprafata_Curte;
}
void Casa::setSuprafata_Curte(double aux) {
    Suprafata_Curte = aux;
}
void Casa::setANIMALE(bool aux) {
    ANIMALE = aux;
}

bool Casa::getANIMALE() const{
    return ANIMALE;

}
const std::vector<std::string> Casa::getAnimale()const{
    return Animale;

}

void Casa::setAnimale(const vector<string> Animalee) {
    this->Animale.clear();
    for(auto element:Animalee){
        Animale.push_back(element);
    }

}
