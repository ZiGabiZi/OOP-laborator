#include <iostream>
#include <cstring>

using namespace std;
class Cladire{
    int nrCamere;
    int idCladire; // Sal las const int? Dar tot se schimba id la copy constructor
    static int contorCladire;
    int nrLocuitori;
    char* Locuitor;
    float Pret;
    bool Chirie;
    float* suprafata; //Lungime si Latime
public:

    Cladire();
    Cladire(int nrLocuitori, float Pret, bool Chirie,
            int nrCamere,float* suprafata, char* Locuitor);

    Cladire(const Cladire &obj);
//    Cladire &operator =(const Cladire &obj);
    ~Cladire();



    float getPret() const{
        return Pret;
    }
    void setPret(float aux){
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
//    void setidCladire(const int aux){
//     this->idCladire = aux;
//    }
    static int getcontorCladire(){
        return contorCladire;
    }

    const float* getsuprafata(){
        return this->suprafata;
    }

    void setSuprafata(float *Suprafata){
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

    friend bool operator==(const Cladire &lhs, const Cladire &rhs);

    friend bool operator!=(const Cladire &lhs, const Cladire &rhs);


};


bool operator==(const Cladire &lhs, const Cladire &rhs) {
    int ok=1;

    for(int i=0; i< lhs.getnrCamere(); i++){
        if (*(lhs.getsuprafata() + i) != *(rhs.getsuprafata() + i)){
            ok = 0;
        }
    }


    return lhs.getnrCamere() == rhs.getnrCamere() &&
           lhs.getidCladire() == rhs.getidCladire() &&
           lhs.getnrLocuitori() == rhs.getnrLocuitori() &&
           strcmp(lhs.getLocuitor(), rhs.getLocuitor()) == 0 &&
           lhs.getPret() == rhs.getPret() &&
           lhs.getChirie() == rhs.getChirie() &&
           ok;
}

bool operator!=(const Cladire &lhs, const Cladire &rhs) {
    return !(rhs == lhs);
}

Cladire::Cladire():idCladire(contorCladire++) {
    nrLocuitori = 0;
    nrCamere = 0;

    Pret = 0.0;
    Chirie = true;

    suprafata = NULL;
    Locuitor = new char [strlen("ANONIM") + 1];
    strcpy(Locuitor, "ANONIM");

}
Cladire::Cladire(int nrLocuitori, float Pret, bool Chirie,
                 int nrCamere,float* suprafata, char* Locuitor):idCladire(contorCladire++){

    this->nrLocuitori = nrLocuitori;
    this->Pret = Pret;
    this->Chirie = Chirie;
    this->nrCamere = nrCamere;

    this->suprafata = new float[nrCamere];
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
    this->suprafata = new float [obj.nrCamere];
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
    float a[]={12.3,45.6,23.4};
    char b[7]="Andrei";
    char c[4]="Ana";
    float V[4] = {10.5,6.3,9.1};


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
        cout << "Egalitate";
    else
        cout << "Inegalitate";



//    int Cost( aux){
//        int
//    }




    return 0;
}
