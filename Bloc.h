#ifndef OOP_BLOC_H
#define OOP_BLOC_H

#include <iostream>
#include <string>
#include "Cladire.h"

class Bloc: public Cladire{
    int etaj;
    int numarUsa;
    int nrInterfon;
public:
    Bloc();
    Bloc(int AnCladire, double Pret, bool Chirie,
         int nrCamere,const std::vector<double> suprafata, const std::string Locuitor,std::string Oras,std::string Strada,int nrStrada, int etaj,
         int numarUsa, int nrInterfon); ///
    Bloc(const Bloc &obj, const Adresa &obi); ///
    Bloc& operator =(const Bloc &obi);
    virtual ~Bloc();
    friend std::ostream& operator <<(std::ostream& out,const Bloc& c2);
    friend std::istream& operator >>(std::istream& in, Bloc& c2);
    void getTip();
    bool operator==(const Bloc &rhs) const;
    bool operator!=(const Bloc &rhs) const;
    int getEtaj() const;
    void setEtaj(int aux);
    int getNumarUsa() const;
    void setNumarUsa(int aux);
    int getNrInterfon() const;
    void setNrInterfon(int aux);


};

#endif //OOP_BLOC_H
