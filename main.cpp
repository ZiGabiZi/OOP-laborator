#include <iostream>
#include <cstring>
#include <fstream>
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
public:

    Cladire();
    Cladire(int AnCladire, double Pret, bool Chirie,
            int nrCamere,const double* suprafata, const char* Locuitor);

    Cladire(const Cladire &obj);
    Cladire &operator =(const Cladire &obj);
    ~Cladire();
    friend ostream& operator <<(ostream& out, const Cladire& c1);
    friend istream& operator >>(istream& in, Cladire& c1);



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
    }


    static int getcontorCladire() {
        return Cladire::contorCladire;
    }


    static void setcontorCladire(const int aux){
        Cladire::contorCladire = aux;
    }




    const double* getsuprafata()const{
        return this->suprafata;
    }

    void setSuprafata(const double *Suprafata, int n){
        double *sp = new double[n];
        for(int i = 0; i < n; i ++)
           sp[i] = Suprafata[i];

        Cladire::suprafata = sp;

    }


    const char* getLocuitor() const{
        return Locuitor;

    }

    void setLocuitor(const char* nume){
        if(this->Locuitor!= nullptr){
            delete[] this->Locuitor;
            this->Locuitor = nullptr;
        }
        int len = strlen(nume) + 1;
        this->Locuitor = new char[len];
        strcpy(this->Locuitor, nume);

    }

    bool operator==(const Cladire &rhs) const{
        for (int i = 0; i < nrCamere; i++) {
            if (suprafata[i] != rhs.suprafata[i])
                return false;
        }

        return nrCamere==rhs.nrCamere && idCladire==rhs.idCladire
               && AnCladire==rhs.AnCladire && strcmp(Locuitor,rhs.Locuitor)==0 && Pret==rhs.Pret && Chirie==rhs.Chirie;
    }

    bool operator!=(const Cladire &rhs) const{
        return !(*this==rhs);
    }

};
Cladire& Cladire::operator =(const Cladire &obj){
    if(this!= &obj)
    {
        if(this->suprafata != nullptr){
            delete[] this->suprafata;
            this->suprafata = nullptr;
        }

        if(this->Locuitor != nullptr){
            delete[] this-> Locuitor;
            this->Locuitor = nullptr;
        }

        this->AnCladire = obj.AnCladire;
        this->Pret = obj.Pret;
        this->Chirie = obj.Chirie;
        this->nrCamere = obj.nrCamere;
        this->suprafata = new double [obj.nrCamere];
        for(int i=0; i<nrCamere;i++){
            this->suprafata[i] = obj.suprafata[i];
        }
        this->Locuitor = new char [strlen(obj.Locuitor) + 1]; ///
        strcpy(this->Locuitor, obj.Locuitor);
        Cladire::idCladire = obj.idCladire;
//        Cladire::contorCladire = obj.contorCladire; //////

    }
    return *this;


}

Cladire::Cladire():idCladire(contorCladire++) {
    AnCladire = 0;
    nrCamere = 0;

    Pret = 0.0;
    Chirie = true;

    suprafata = nullptr;
    Locuitor = new char [strlen("ANONIM") + 1];
    strcpy(Locuitor, "ANONIM");


}
Cladire::Cladire(int AnCladire, double Pret, bool Chirie,
                 int nrCamere,const double* suprafata, const char* Locuitor):idCladire(contorCladire++){

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
    this->Locuitor = new char [strlen(obj.Locuitor) + 1]; ///
    strcpy(this->Locuitor, obj.Locuitor);


}


Cladire::~Cladire(){
    if(this->suprafata!= nullptr){
        delete[] this->suprafata;
        this->suprafata = nullptr;
    }
    if(this->Locuitor!= nullptr){
        delete[] this-> Locuitor;
        this->Locuitor = nullptr;
    }
}


int Cladire::contorCladire = 0;

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


    double *sp = new double [c1.nrCamere];
    for(int i=0; i<c1.nrCamere;i++){
        cout<< "Dati suprafata camerei " << i+1 << ": ";
        in >> sp[i];
    }
    c1.setSuprafata(sp, c1.nrCamere);

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



int main() {
    double *a = new double[3]{12.3,45.6,23.4};

    const char *b = new char[7] {'I', 'o','n','e','l','a'};

    const char *c = new char[4]{'A','n','a'};
    double *V = new double [3]{10.5, 6.3, 9.1};

//
//
//    Cladire s1(10,123.3,true,3,a,b);
//    cout << s1.getPret() <<" este Pret OB 1" << endl << s1.getChirie()<< " este Chirie OB1" << endl << s1.getidCladire() <<" este ID OB1" << endl;
//    Cladire s2(s1);
//    cout << s2.getidCladire() << " este ID OB2" << endl << s2.getnrCamere() << " Sunt Camerele la OB2" << endl;
//
//    for(int i=0; i< s1.getnrCamere(); i++){
//        cout <<"Suprafata camerei "<< i<< " Este de "<< s1.getsuprafata()[i] << " metri patrati."<< endl;
//
//    }
//    s1.setLocuitor(c);
//    cout << s1.getidCladire() << endl;
//    cout << s2.getidCladire() << endl << s1.getLocuitor() << endl << s2.getLocuitor() << endl;
//
//    s1.setSuprafata(V);
//
//
//    for(int i=0; i< s1.getnrCamere(); i++){
//        cout << "Suprafata camerei " << i << " este de " << *(s1.getsuprafata() + i)  << " metri patrati" << endl;
//    }
//    s1.setidCladire(70);
//
//    cout << s1.getcontorCladire() << endl << s2.getcontorCladire() << endl; //Contor cladire este aceleasi pentru toate si reprezinta nr-ul de obiecte construite
//
//
//
//    Cladire s3(s2);
//    cout << s3.getidCladire() << endl << s1.getidCladire() << endl; // id cladire s3=2; id cladire s1=70
//    cout << s3.getLocuitor() << endl << s1.getLocuitor() << endl;
////    cout << s3.getsuprafata() << endl << s1.getsuprafata() << endl; //Va returna adresa primului elem.
//
//
//    s3=s1;
//
//
//    if (s1 == s3)
//        cout << "Egalitate" << endl;
//    else
//        cout << "Inegalitate" << endl;
//
//    if (s1!=s3)
//        cout<<"Nu" << endl;
//
//
//    Cladire s4;
//    Cladire s5;
//
//
//    if(s3!=s2)
//        cout << "Nu" << endl;
//
//    s3=s2;
//    if(s3!=s2)
//        cout << "Nu" << endl;
//
//    if(s2!=s1)
//        cout <<"Nu sunt egale"<< endl;
//
//    s3.setcontorCladire(8);
//
//
//    cout << s3.getidCladire() << endl << s2.getidCladire() << endl << s4.getidCladire() << endl << s3.getcontorCladire() << endl << s4.getcontorCladire();
//    cout << endl << s5.getcontorCladire() << endl << s1.getcontorCladire();
//
//    s3.setnrCamere(5);
//    cout << endl << "Numar camere OB 3 dupa setare: "<< s3.getnrCamere() << endl;
//    s3.setPret(80);
//    s3.setChirie(false);
//    s3.setAnCladire(2005);
//    cout << s3.getAnCladire();
    Cladire s1;
    Cladire s2(2004, 9000, true, 3, a, b);
    Cladire s3(2019, 5600, false, 3, V, c);
    Cladire s4(s3);
    Cladire s5;

    s5 = s4;

    s3.setPret(500);
    cout << s3.getPret() << endl;
    cout << s3.getAnCladire() << endl;
    s3.setAnCladire(2020);
    cout << s3.getAnCladire() << endl;
    s3.setnrCamere(3);
    cout << s3.getnrCamere() << endl;
    s3.setSuprafata(a, 3);


    for (int i = 0; i < s3.getnrCamere(); i++) {

        cout << "Camera " << i + 1 << " are dimensiunea de " << s3.getsuprafata()[i] << " metri patrati." << endl;
    }
    cout << s3.getLocuitor() << endl;
    s3.setLocuitor(b);
    cout << s3.getLocuitor() << endl;
    if (s3.getChirie() == 1)
        cout << s3.getLocuitor() << " plateste " << s3.getPret() << " lei lunar chirie" << endl;
    else
        cout << s3.getLocuitor() << " a platit" << s3.getPret() << " pentru casa in care locuieste." << endl;
    s3.setChirie(true);
    if (s3.getChirie() == 1)
        cout << s3.getLocuitor() << " plateste " << s3.getPret() << " lei lunar chirie" << endl;
    else
        cout << s3.getLocuitor() << " a platit" << s3.getPret() << " pentru casa in care locuieste." << endl;
    cout << s3.getidCladire() << " este ID-ul cladirii 3" << endl << s1.getidCladire() << "este ID-ul cladirii 1" << endl;
    s1.setidCladire(10);
    cout << s3.getidCladire() << " este ID-ul cladirii 3" << endl << s1.getidCladire() << " este ID-ul cladirii 1" << endl;

    cout << s3.getcontorCladire()<<endl;
    s3.setcontorCladire(69);
    cout<< s3.getcontorCladire()<<endl;


//    ifstream f("C:\\Users\\User\\Documents\\GitHub\\OOP-laborator\\tastatura.txt");
    ifstream f("tastatura.txt");


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
        cout << comanda;
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
                break;

            }
            default: {
                cout << "\n\tComanda Necunoscuta";
            }

        }
    }



    f.close();



    delete[] a;
    delete[] b;
    delete[] c;
    delete[] V;


    return 0;

}