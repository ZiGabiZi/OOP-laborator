#ifndef OOP_CLADIRE_H
#define OOP_CLADIRE_H

#include <iostream>
#include <vector>
using namespace std;

class Cladire{
    int nrCamere;
    int idCladire;
    static int contorCladire;
    int AnCladire;
    char* Locuitor;
    double Pret;
    bool Chirie;
    double* suprafata;
//    vector<double> suprafata;
public:
    Cladire();
    Cladire(int AnCladire, double Pret, bool Chirie,
            int nrCamere,const double* suprafata, const char* Locuitor);

    Cladire(const Cladire &obj);
    Cladire &operator =(const Cladire &obj);
    ~Cladire();
    friend ostream& operator <<(ostream& out, const Cladire& c1);
    friend istream& operator >>(istream& in, Cladire& c1);

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
    const double* getsuprafata()const;
    void setSuprafata(const double *Suprafata, int n);
    const char* getLocuitor() const;
    void setLocuitor(const char* nume);
    bool operator==(const Cladire &rhs) const;
    bool operator!=(const Cladire &rhs) const;


};

#endif //OOP_CLADIRE_H
