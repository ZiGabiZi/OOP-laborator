#ifndef OOP_CLADIRE_H
#define OOP_CLADIRE_H

#include <iostream>
#include <vector>
#include <string>
#include "Adresa.h"


class Cladire{
protected:
    int nrCamere;
    int idCladire;
    static int contorCladire;
    int AnCladire;
    std::string Locuitor;
    double Pret;
    bool Chirie;
    std::vector<double> suprafata;
    Adresa adresa;
public:
    Cladire();
    Cladire(int AnCladire, double Pret, bool Chirie,
            int nrCamere,const std::vector<double> suprafata, const std::string Locuitor,std::string Oras,std::string Strada,int nrStrada);

    Cladire(const Cladire &obj, const Adresa &ob);
    Cladire &operator =(const Cladire &obj);
    virtual ~Cladire();
    virtual void Afisare(std::ostream& out) const;
    virtual void Citire(std::istream& in);
    friend std::ostream& operator <<(std::ostream& out, const Cladire& c1);
    friend std::istream& operator >>(std::istream& in, Cladire& c1);
//    virtual void getTip() = 0;

    double getPret() const;
    void setPret(double aux);
    bool getChirie() const;
    void setChirie(bool aux);
    int getAnCladire() const;
    void setAnCladire(int aux);
    int getnrCamere() const;
    void setnrCamere(int aux);
    int getidCladire() const;
    void setidCladire(const int aux);
    static int getcontorCladire();
    static void setcontorCladire(const int aux);
    const std::vector<double> getsuprafata()const;
    void setSuprafata(const std::vector<double> Suprafata);
    const std::string getLocuitor() const;
    void setLocuitor(const std::string nume);
    bool operator==(const Cladire &rhs) const;
    bool operator!=(const Cladire &rhs) const;
    const std::string getOrasAdresa() const;
    void setOrasAdresa(const std::string ORAS);
    const std::string getStradaAdresa() const;
    void setStradaAdresa(const std::string STRADA);
    int getnrStradaAdresa() const;
    void setnrStradaAdresa(int NRSTRADA);

};

#endif //OOP_CLADIRE_H
