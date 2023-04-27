#include <iostream>
#include <string>
#ifndef OOP_ADRESA_H
#define OOP_ADRESA_H

class Adresa{
    std::string Oras;
    std::string Strada;
    int nrStrada;

public:
    Adresa();
    Adresa(std::string Oras, std::string Strada, int nrStrada);
    virtual void afis();
    Adresa(const Adresa &);
    Adresa &operator =(const Adresa &obj);
    friend std::ostream& operator <<(std::ostream& out, const Adresa& c1);
    friend std::istream& operator >>(std::istream& in, Adresa& c1);
    
    const std::string getOras() const;
    void setOras(const std::string ORAS);

    const std::string getStrada() const;
    void setStrada(const std::string STRADA);

    int getnrStrada() const;
    void setnrStrada(const int NRSTRADA);
    
    

};



#endif //OOP_ADRESA_H
