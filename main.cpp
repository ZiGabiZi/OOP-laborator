#include <iostream>
#include <cstring>

using namespace std;
class Cladire{
    int nrCamere;
    int idCladire; // Sal las const int? Dar tot se schimba id la copy constructor
    static int contorCladire;
    int nrLocuitori;
    char* Locuitor;
    double Pret;
    bool Chirie;
    double* suprafata; //Lungime si Latime
public:

    Cladire();
    Cladire(int nrLocuitori, double Pret, bool Chirie,
            int nrCamere,double* suprafata, char* Locuitor);

    Cladire(const Cladire &obj);
    Cladire &operator =(const Cladire &obj);
    ~Cladire();



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
    int getnrLocuitori() const{
        return nrLocuitori;
    }
    void setnrLocuitori(int aux){
        this->nrLocuitori = aux;
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
        && nrLocuitori==rhs.nrLocuitori && strcmp(Locuitor,rhs.Locuitor)==0 && Pret==rhs.Pret && Chirie==rhs.Chirie;
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

        this->nrLocuitori = obj.nrLocuitori;
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
    nrLocuitori = 0;
    nrCamere = 0;

    Pret = 0.0;
    Chirie = true;

    suprafata = NULL;
    Locuitor = new char [strlen("ANONIM") + 1];
    strcpy(Locuitor, "ANONIM");
    idCladire = 0;

}
Cladire::Cladire(int nrLocuitori, double Pret, bool Chirie,
                 int nrCamere,double* suprafata, char* Locuitor):idCladire(contorCladire++){

    this->nrLocuitori = nrLocuitori;
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
    this->nrLocuitori = obj.nrLocuitori;
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

    Cladire s3(s1);
    cout << s3.getidCladire() << endl << s1.getidCladire() << endl;
    cout << s3.getLocuitor() << endl << s1.getLocuitor() << endl;
    cout << s3.getsuprafata() << endl << s1.getsuprafata() << endl;




    if (s1 == s3)
        cout << "Egalitate" << endl;
    else
        cout << "Inegalitate" << endl;

    if (s1!=s3)
        cout<<"Nu" << endl;






    return 0;
}
