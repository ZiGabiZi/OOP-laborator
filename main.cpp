#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
class Cladire{
    int nrCamere;
    int idCladire; // Sal las const int? Dar tot se schimba id la copy constructor
    static int contorCladire;
    int AnCladire;
    char* Locuitor;
    double Pret;
    bool Chirie;
    double* suprafata; //Lungime si Latime
public:

    Cladire();
    Cladire(int AnCladire, double Pret, bool Chirie,
            int nrCamere,double* suprafata, char* Locuitor);

    Cladire(const Cladire &obj);
    Cladire &operator =(const Cladire &obj);
    ~Cladire();
    friend ostream& operator <<(ostream& out, const Cladire& c1);
    friend istream& operator >>(istream& out, Cladire& c1);



    double getPret() const{
        return Pret;
    }
    void setPret(double aux){
        this->Pret = aux;
    }
    bool getChirie() const{
        return Chirie;
    }
    void setChirie(bool aux){
        this->Chirie = aux;
    }
    int getAnCladire() const{
        return AnCladire;
    }
    void setAnCladire(int aux){
        this->AnCladire = aux;
    }
    int getnrCamere() const {
        return nrCamere;
    }
    void setnrCamere(int aux){
        this->nrCamere = aux;
    }

    int getidCladire() const {
        return idCladire;
    }
    void setidCladire(const int aux){
     this->idCladire = aux;
    } //la const int nu merge


    static int getcontorCladire(){
        return contorCladire;
    }


    static void setcontorCladire(const int aux){
        Cladire::contorCladire = aux;
    } // ???




    const double* getsuprafata()const{
        return this->suprafata;
    }

    void setSuprafata(double *Suprafata){
        Cladire::suprafata = Suprafata;
    }


    const char* getLocuitor() const{
        return Locuitor;

    }

    void setLocuitor(char* nume){
        delete[] this->Locuitor;
        int len = strlen(nume) + 1;
        this->Locuitor = new char[len];
        strcpy(this->Locuitor, nume);

    }

    bool operator==(const Cladire &rhs) const{
        for(int i=0;i<nrCamere;i++){
            if(suprafata[i]!=rhs.suprafata[i])
                return 0;
        }
        return nrCamere==rhs.nrCamere && idCladire==rhs.idCladire
        && AnCladire==rhs.AnCladire && strcmp(Locuitor,rhs.Locuitor)==0 && Pret==rhs.Pret && Chirie==rhs.Chirie;
    }

   bool operator!=(const Cladire &rhs) const{
        return *this==rhs;
    }

};
Cladire& Cladire::operator =(const Cladire &obj){
    if(this!= &obj)
    {
        if(this->suprafata != NULL){
            delete[] this->suprafata;
        this->suprafata = NULL;}

        if(this->Locuitor != NULL){
            delete[] this-> Locuitor;
        this->Locuitor = NULL;}

        this->AnCladire = obj.AnCladire;
        this->Pret = obj.Pret;
        this->Chirie = obj.Chirie;
        this->nrCamere = obj.nrCamere;
        this->suprafata = new double [obj.nrCamere];
        for(int i=0; i<nrCamere;i++){
            this->suprafata[i] = obj.suprafata[i];
        }
        this->Locuitor = new char [strlen(obj.Locuitor) + 1];
        strcpy(this->Locuitor, obj.Locuitor);
        Cladire::idCladire = obj.idCladire;
        Cladire::contorCladire = obj.contorCladire;

    }
    return *this;


}

Cladire::Cladire():idCladire(contorCladire++) {
    AnCladire = 0;
    nrCamere = 0;

    Pret = 0.0;
    Chirie = true;

    suprafata = NULL;
    Locuitor = new char [strlen("ANONIM") + 1];
    strcpy(Locuitor, "ANONIM");


}
Cladire::Cladire(int AnCladire, double Pret, bool Chirie,
                 int nrCamere,double* suprafata, char* Locuitor):idCladire(contorCladire++){

    this->AnCladire = AnCladire;
    this->Pret = Pret;
    this->Chirie = Chirie;
    this->nrCamere = nrCamere;

    this->suprafata = new double[nrCamere];
    for(int i=0; i<nrCamere; i++){
        this->suprafata[i] = *(suprafata+i);
    }
    this->Locuitor = new char [strlen(Locuitor) + 1];
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
    this->Locuitor = new char [strlen(obj.Locuitor) + 1];
    strcpy(this->Locuitor, obj.Locuitor);
//    Cladire::idCladire = obj.idCladire;
//    Cladire::contorCladire = obj.contorCladire;



}
Cladire::~Cladire(){
    if(this->suprafata != NULL)
        delete[] this->suprafata;
    this->suprafata = NULL;

    if(this->Locuitor != NULL)
        delete[] this-> Locuitor;
    this->Locuitor = NULL;
}


int Cladire::contorCladire = 0;

ostream& operator <<(ostream& out, const Cladire& c1){
    out << "ID Cladire este: " <<  c1.idCladire - 999 << endl;
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
istream& operator >>(istream& in, Cladire& c1){
    cout << "Dati nr camere: ";
    in >> c1.nrCamere;

    if(c1.suprafata != NULL){
        delete[] c1.suprafata;}
    c1.suprafata = new double [c1.nrCamere];
    for(int i=0; i<c1.nrCamere;i++){
        cout<< "Dati suprafata camerei " << i+1 << ": ";
        in >> c1.suprafata[i];
    }
    cout << "Dati anul in care a fost construita cladirea: ";
    in >> c1.AnCladire;

    cout << "Dati numele locuitorului: ";
    char aux[20];
    in >> aux;
    if(c1.Locuitor != NULL){
        delete[] c1.Locuitor;
    }
    c1.Locuitor = new char[strlen(aux) + 1];
    strcpy(c1.Locuitor,aux);

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



int main()
{
    double a[]={12.3,45.6,23.4};
    char b[7]="Andrei";
    char c[4]="Ana";
    double V[4] = {10.5,6.3,9.1};


    Cladire s1(10,123.3,true,3,a,b);
    cout << s1.getPret() <<" este Pret OB 1" << endl << s1.getChirie()<< " este Chirie OB1" << endl << s1.getidCladire() <<" este ID OB1" << endl;
    Cladire s2(s1);
    cout << s2.getidCladire() << " este ID OB2" << endl << s2.getnrCamere() << " Sunt Camerele la OB2" << endl;

    for(int i=0; i< s1.getnrCamere(); i++){
        cout <<"Suprafata camerei "<< i<< " Este de "<< s1.getsuprafata()[i] << " metri patrati."<< endl;

    }
    s1.setLocuitor(c);
    cout << s1.getidCladire() << endl;
    cout << s2.getidCladire() << endl << s1.getLocuitor() << endl << s2.getLocuitor() << endl;

    s1.setSuprafata(V);


    for(int i=0; i< s1.getnrCamere(); i++){
        cout << "Suprafata camerei " << i << " este de " << *(s1.getsuprafata() + i)  << " metri patrati" << endl;
    }
    s1.setidCladire(70);

    cout << s1.getcontorCladire() << endl << s2.getcontorCladire() << endl; //Contor cladire este aceleasi pentru toate si reprezinta nr-ul de obiecte construite



    Cladire s3(s2);
    cout << s3.getidCladire() << endl << s1.getidCladire() << endl; // id cladire s3=2; id cladire s1=70
    cout << s3.getLocuitor() << endl << s1.getLocuitor() << endl;
//    cout << s3.getsuprafata() << endl << s1.getsuprafata() << endl; //Va returna adresa primului elem.


    s3=s1;


    if (s1 == s3)
        cout << "Egalitate" << endl;
    else
        cout << "Inegalitate" << endl;

    if (s1!=s3)
        cout<<"Nu" << endl;


    Cladire s4;
    Cladire s5;

    s3.setcontorCladire(8);


    cout << s3.getidCladire() << endl << s2.getidCladire() << endl << s4.getidCladire() << endl << s3.getcontorCladire() << endl << s4.getcontorCladire();
    cout << endl << s5.getcontorCladire() << endl << s1.getcontorCladire();

    s3.setnrCamere(5);
    cout << endl << "Numar camere OB 3 dupa setare: "<< s3.getnrCamere() << endl;
    s3.setPret(80);
    s3.setChirie(false);
    s3.setAnCladire(2005);
    cout << s3.getAnCladire();

ifstream f("tastatura.txt");


if(f.is_open()) {


    int n;
    cout << "Cate obiecte doriti sa citi? ";
    f >> n;
    Cladire ListaCladiri[1000];
    int contor = 0;
    int k = 1;
    while (k == 1 && (contor < n)) {
        int comanda;
        cout << "\n1-Citeste obiect;";
        cout << "\n2-Afiseaza Lista Obiecte;";
        cout << "\n3-STOP";
        cout << endl;
        f >> comanda;
        switch (comanda) {
            case 1: {
                Cladire h;
                f >> h;
                ListaCladiri[contor] = h;
                contor++;
                break;
            }
            case 2: {
                for (int i = 0; i < contor; i++)
                    cout << ListaCladiri[i] << endl;
                break;
            }
            case 3: {

                k = 0;
                break;
            }
            default: {
                cout << "\n\tComanda Necunoscuta";
            }


        }

    }
    if (k == 1 || contor == n) {
        int comanda2;
        cout << "\nNu mai puteti citi mai multe Obiecte";
        cout << "\n1-Afiseaza Lista Obiecte;";
        cout << "\n2-STOP";
        cout << endl;
        f >> comanda2;
        switch (comanda2) {
            case 1: {
                for (int i = 0; i < contor; i++)
                    cout << ListaCladiri[i] << endl;
                break;
            }
            case 2: {

                k = 0;
                break;
            }
            default: {
                cout << "\n\tComanda Necunoscuta";
            }

        }
    }

}
    f.close();

    return 0;
}
