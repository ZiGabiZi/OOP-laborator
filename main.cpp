#include <iostream>
#include "Cladire.h"
#include "Bloc.h"
#include "Casa.h"
#include <fstream>
#include <memory>
using namespace std;
int main() {
    vector<double> a = {12.3, 45.6, 23.4};
    vector<string> h = {"Caine", "Pisica"};
    const string b = "Ionela";

    const string c = "Ana";
    vector<double> V = {10.5, 6.3, 9.1};

    Cladire s;
    cout << "Testare constructor neparametrizat!" << endl;
    cout << s;
    cout << "----------------------------------------------------------------------------------------------------";
    Casa k(2000, 500,true,3,a,"Gabi","tARGOVISTE","cT BV", 266, 1000,2,true,h);
    cout << "Testare constructor parametrizat!" << endl;
    cout << k;
    cout << "----------------------------------------------------------------------------------------------------";

    cout << "Testare upcasting" << endl;
    Cladire* aux = new Casa(2000, 500,true,3,a,"Gabi","tARGOVISTE","cT BV", 266, 1000,2,true,h);
    cout << *aux;
    cout << "----------------------------------------------------------------------------------------------------";

    cout << "Testare Dynamic Cast/Down Cast" << endl;
    Casa* b1 = dynamic_cast<Casa*>(aux);
    cout << *b1;
    delete aux;
    cout << "----------------------------------------------------------------------------------------------------";
    Casa auxx;
    cin >> auxx;
///SMART POINTERS
    Casa* ceva;
    ceva = &k;
    Casa* ceva2;
    ceva2 = &k;
    shared_ptr<Casa> k2 = make_shared<Casa>(2000, 500,true,3,a,"Gabi","tARGOVISTE","cT BV", 266, 1000,2,true,h);
    cout << *ceva << *ceva2;
    cout << k2.use_count();


//    Cladire s1;
//    Cladire s2(2004, 9000, true, 3, a, b, "Budapesta", "Tudor", 69);
//    cout << s2;
//    Cladire s3(2019, 5600, false, 3, V, c);
//    Cladire s4(s3);
//    Cladire s5;
//
//    s5 = s4;
//
//    s3.setPret(500);
//    cout << s3.getPret() << endl;
//    cout << s3.getAnCladire() << endl;
//    s3.setAnCladire(2020);
//    cout << s3.getAnCladire() << endl;
//    s3.setnrCamere(3);
//    cout << s3.getnrCamere() << endl;
//    s3.setSuprafata(a);
//
//
//    for (int i = 0; i < s3.getnrCamere(); i++) {
//
//        cout << "Camera " << i + 1 << " are dimensiunea de " << s3.getsuprafata()[i] << " metri patrati." << endl;
//    }
//    cout << s3.getLocuitor() << endl;
//    s3.setLocuitor(b);
//    cout << s3.getLocuitor() << endl;
//    if (s3.getChirie() == 1)
//        cout << s3.getLocuitor() << " plateste " << s3.getPret() << " lei lunar chirie" << endl;
//    else
//        cout << s3.getLocuitor() << " a platit" << s3.getPret() << " pentru casa in care locuieste." << endl;
//    s3.setChirie(true);
//    if (s3.getChirie() == 1)
//        cout << s3.getLocuitor() << " plateste " << s3.getPret() << " lei lunar chirie" << endl;
//    else
//        cout << s3.getLocuitor() << " a platit" << s3.getPret() << " pentru casa in care locuieste." << endl;
//    cout << s3.getidCladire() << " este ID-ul cladirii 3" << endl << s1.getidCladire() << "este ID-ul cladirii 1" << endl;
//    s1.setidCladire(10);
//    cout << s3.getidCladire() << " este ID-ul cladirii 3" << endl << s1.getidCladire() << " este ID-ul cladirii 1" << endl;
//
//    cout << s3.getcontorCladire()<<endl;
//    s3.setcontorCladire(69);
//    cout<< s3.getcontorCladire()<<endl;


//    ifstream f("C:\\Users\\User\\Documents\\GitHub\\OOP-laborator\\tastatura.txt");
////    ifstream f("tastatura.txt");
//
//
//    int n;
//    cout << "Cate obiecte doriti sa citi? ";
//    f >> n;
//    Cladire ListaCladiri[1000];
//    int contor = 0;
//    int k = 1;
//    while (k == 1 && (contor < n)) {
//        int comanda;
//        cout << "\n1-Citeste obiect;";
//        cout << "\n2-Afiseaza Lista Obiecte;";
//        cout << "\n3-STOP";
//        cout << endl;
//        f >> comanda;
////        cout << comanda;
//        switch (comanda) {
//            case 1: {
//                Cladire h;
//                f >> h;
//                ListaCladiri[contor] = h;
//                contor++;
//                break;
//            }
//            case 2: {
//                for (int i = 0; i < contor; i++)
//                    cout << ListaCladiri[i] << endl;
//                break;
//            }
//            case 3: {
//
//                k = 0;
//                break;
//            }
//            default: {
//                cout << "\n\tComanda Necunoscuta";
//            }
//
//
//        }
//
//    }
//    if (k == 1 || contor == n) {
//        int comanda2;
//        cout << "\nNu mai puteti citi mai multe Obiecte";
//        cout << "\n1-Afiseaza Lista Obiecte;";
//        cout << "\n2-STOP";
//        cout << endl;
//        f >> comanda2;
//        switch (comanda2) {
//            case 1: {
//                for (int i = 0; i < contor; i++)
//                    cout << ListaCladiri[i] << endl;
//                break;
//            }
//            case 2: {
//                break;
//
//            }
//            default: {
//                cout << "\n\tComanda Necunoscuta";
//            }
//
//        }
//    }
//
//
//
//    f.close();
//
//
//
//
//    return 0;
//
//
}