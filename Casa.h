#ifndef OOP_CASA_H
#define OOP_CASA_H
#include <iostream>
#include "Cladire.h"
#include <string>

class Casa:public Cladire{
    double Suprafata_Curte;
    int etaje;
    bool ANIMALE;
    std::vector<std::string> Animale;
public:
    Casa();
    Casa(int AnCladire, double Pret, bool Chirie,
         int nrCamere,const std::vector<double> suprafata, const std::string Locuitor,std::string Oras,std::string Strada,int nrStrada,
         double Suprafata_Curte, int etaje, bool ANIMALE, const std::vector<std::string> Animale);
    Casa(const Casa &obj);
    Casa& operator =(const Casa &obi);
    virtual ~Casa();
    friend std::ostream& operator <<(std::ostream& out,const Casa& c2);
    friend std::istream& operator >>(std::istream& in, Casa& c2);
    void getTip();
    bool operator==(const Casa &rhs) const;
    bool operator!=(const Casa &rhs) const;
    int getEtaje() const;
    void setEtaje(int aux);
    double getSuprafata_Curte() const;
    void setSuprafata_Curte(double aux);
    bool getANIMALE() const;
    void setANIMALE(bool aux);
    const std::vector<std::string> getAnimale()const;
    void setAnimale(const std::vector<std::string> Animalee);

};


#endif //OOP_CASA_H
