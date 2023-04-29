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
    cout << s<< endl;
    cout << "----------------------------------------------------------------------------------------------------"<< endl;
    Casa k(2000, 500,true,3,a,"Gabi","tARGOVISTE","cT BV", 266, 1000,2,true,h);
    cout << "Testare constructor parametrizat!" << endl;
    cout << k<< endl;
    cout << "----------------------------------------------------------------------------------------------------"<< endl;

    cout << "Testare upcasting" << endl;
    Cladire* aux = new Casa(2000, 500,true,3,a,"Gabi","tARGOVISTE","cT BV", 266, 1000,2,true,h);
    cout << *aux << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;

    cout << "Testare Dynamic Cast/Down Cast" << endl;
    Casa* b1 = dynamic_cast<Casa*>(aux);
    cout << *b1 << endl;
    delete aux;
    cout << "----------------------------------------------------------------------------------------------------"<<endl;
    Casa auxx;
    cin >> auxx;
///SMART POINTERS
    Casa* ceva;
    ceva = &k;
    Casa* ceva2;
    ceva2 = &k;
    shared_ptr<Casa> k2 = make_shared<Casa>(2000, 500,true,3,a,"Gabi","tARGOVISTE","cT BV", 266, 1000,2,true,h);
    cout << *ceva << *ceva2 << endl;
    cout << k2.use_count() << endl;

    /// MENIU INTERACTIV
    int n;
    cout << "Cate obiecte de tip Casa doriti sa citi? ";
    cin >> n;

    int n2;
    cout << "Cate obiecte de tip Bloc doriti sa citi? ";
    cin >> n2;

    vector<Casa> ObCasa;
    vector<Bloc> ObBloc;


    cout << "Specificati ce tip de obiecte vreti sa creati prima dara. Scrieti Casa sau Bloc";
    string tip;
    cin >> tip;

    if (tip == "Casa"){
        int contor = 0;
        int k_aux = 1;
        while (contor < n && k_aux == 1){
            int comanda;
            cout << "\n1-Citeste obiect;";
            cout << "\n2-Afiseaza Lista Obiecte;";
            cout << "\n3-Sterge Obiect";
            cout << "\n4-Modifica Obiect";
            cout << "\n5-STOP";

            cin >> comanda;

            switch (comanda) {
                case 1:{
                    Casa o;
                    cin >> o;
                    ObCasa.push_back(o);
                    contor++;
                    break;
                }

                case 2:{
                    for(auto item = ObCasa.rbegin();item != ObCasa.rend();item++){
                        cout << *item << endl;
                    }
                    break;
                }
                case 3:{
                    if (contor == 0){
                        cout << "Din pacate nu exista obiecte create inca!" << endl;
                        break;
                    }
                    int ob_del;
                    cout << "Specificati numarul obiectului pe care doriti sa il stergeti: ";
                    cin >> ob_del;
                    if(ob_del > contor){
                        cout<<"Din pacate a-ti selectat un obiect care inca nu a fost creat!"<<endl;
                    }
                    ObCasa.erase(ObCasa.begin()+ob_del-1);
                    contor--;
                    break;

                }

                case 4:{
                    cout << "Specificati numarul obiectului pe care doriti sa il modificati: ";
                    int modif_ob;
                    cin >> modif_ob;
                    cout << "Specificati ce doriti sa modificati la acel obiect: " << endl;

                    int k_aux2 = 1;
                    while(k_aux2 == 1){
                        int modif;
                        cout << "\n1-Numarul de camere;";
                        cout << "\n2-Anul in care a fost construita cladirea;";
                        cout << "\n3-Numele locuitorului";
                        cout << "\n4-Daca plateste chirie sau nu[true/false]";
                        cout << "\n5-Cat plateste chirie lunar sau cat a platit pentru casa";
                        cout << "\n6-Suprafata fiecarei camere a casei";
                        cout << "\n7-Orasul in care locuieste";
                        cout << "\n8-Strada pe care locuieste";
                        cout << "\n9-Numarul strazii pe care locuieste";
                        cout << "\n10-Suprafata curtii";
                        cout << "\n11-Cate etaje sa aiba casa";
                        cout << "\n12-Daca sa aiba animale";
                        cout << "\n13-Animalele pe care sa le aiba";
                        cout << "\n14-Nu mai doresc sa modific nimic!";

                        cin >> modif;

                        switch (modif) {
                            case 1:{
                                int nrCamere, aux3;
                                cout << "Specificati cate camere doriti sa aiba casa: ";
                                cin >> nrCamere;
                                aux3 = ObCasa[modif_ob].getnrCamere();
                                ObCasa[modif_ob].setnrCamere(nrCamere);
                                if(nrCamere > aux3){
                                    cout << "A-ti adaugat " << nrCamere-aux3 << " camere in plus, deci trebuie specificate si suprafetele acestora!" << endl;
                                    vector<double> suprafata2;
                                    suprafata2 = ObCasa[modif_ob].getsuprafata();

                                    int i = 1;
                                    while(i<=nrCamere-aux3){
                                        cout << "Specificati suprafata camerei " << i << "nou adaugate: ";
                                        double sup_aux;
                                        cin >> sup_aux;
                                        suprafata2.push_back(sup_aux);
                                        i++;

                                    }
                                    ObCasa[modif_ob].setSuprafata(suprafata2);

                                }

                                else if(nrCamere < aux3){
                                    cout << "A-ti setat nr de camere ca fiind mai mic decat cel anterior , prin urmare trebuie sa specificati ce camere doriti sa stergeti"<<endl;
                                    cout << "Va trebui sa stergeti " << aux3 - nrCamere << " camere!" << endl;
                                    int aux4 = aux3 - nrCamere;
                                    while (aux4 != 0){
                                        cout << "Avem la dispozitie camerele: ";
                                        for(int i=1;i<=ObCasa[modif_ob].getnrCamere();i++){
                                            cout << i << ". cu suprafata: " << ObCasa[modif_ob].getsuprafata()[i] << endl;
                                        }
                                        cout << "Alegeti numarul camerei pe care doriti sa il stergeti: ";
                                        int nrCamera;
                                        double aux_it;
                                        cin >> nrCamera;
                                        vector<double> suprafata2;
                                        suprafata2 = ObCasa[modif_ob].getsuprafata();
                                        aux_it = suprafata2.begin()+nrCamera; ///


                                    }




                                }
                                break;

                            }

                            case 2:{
                                int an;
                                cout << "Specificati noul an: ";
                                cin >> an;
                                ObCasa[modif_ob].setAnCladire(an);
                                break;

                            }

                            case 3:{
                                string nume;
                                cout << "Dati noul nume al locuitorului: ";
                                cin >> nume;
                                ObCasa[modif_ob].setLocuitor(nume);
                                break;

                            }
                            case 4:{
                                bool chirie;
                                cout << "Specificati daca locuitorul sta cu chirie sau a cumparat casa[true/false]." << endl;
                                cout << "Scrieti true daca vreti sa stea cu chirie sau nu in caz contrat(a cumparat casa): ";
                                cin >> chirie;
                                ObCasa[modif_ob].setChirie(chirie);
                                break;

                            }
                            case 5:{
                                double chirie;
                                if (ObCasa[modif_ob].getChirie() == true){
                                    cout << "Specificati noua suma pe care doriti sa o plateasca lunar la chirie: ";
                                    cin >> chirie;
                                    ObCasa[modif_ob].setPret(chirie);
                                    break;

                                }
                                else{
                                    cout << "Specificati noua suma pe care doriti sa o fi platit proprietarul pentru casa: ";
                                    cin >> chirie;
                                    ObCasa[modif_ob].setPret(chirie);
                                    break;

                                }

                            }
                            case 6:{
                                vector<double> suprafete;
                                int aux7;
                                aux7 = ObCasa[modif_ob].getsuprafata().size();
                                for(int i=1;i<=aux7;i++){
                                    double aux8;
                                    cout << "Specificati suprafata camereri " << i << " : ";
                                    cin >> aux8;
                                    suprafete.push_back(aux8);

                                }
                                ObCasa[modif_ob].setSuprafata(suprafete);
                                break;

                            }

                            case 7:{
                                cout << "Specificati orasul in care doriti sa locuiasca: ";
                                string oras;
                                cin >> oras;
                                ObCasa[modif_ob].setOrasAdresa(oras);
                                break;

                            }

                            case 8:{
                                cout << "Specificati Sstrada pe care doriti sa locuiasca: ";
                                string strada;
                                cin >> strada;
                                ObCasa[modif_ob].setStradaAdresa(strada);
                                break;

                            }
                            case 9:{
                                cout << "Specificati numarul strazii pe care doriti sa locuiasca: ";
                                int nr;
                                cin >> nr;
                                ObCasa[modif_ob].setnrStradaAdresa(nr);
                                break;

                            }

                            case 10:{
                                double suprafata;
                                cout << "Specificati cat doriti sa aiba ca suprafata curtea casei: ";
                                cin >> suprafata;
                                ObCasa[modif_ob].setSuprafata_Curte(suprafata);
                                break;

                            }
                            case 11:{
                                int etaje;
                                cout << "Specificati cate etaje doriti sa aiba casa: ";
                                cin >> etaje;
                                ObCasa[modif_ob].setEtaje(etaje);
                                break;

                            }
                            case 12:{
                                bool animale;
                                cout << "Specificati daca doriti ca proprietarul sa aiba animale[true/false]: ";
                                cin >> animale;
                                ObCasa[modif_ob].setANIMALE(animale);
                                break;
                            }
                            case 13:{
                                vector<string> animale;
                                int k13 =1;
                                while (k13 == 1){
                                    string anim;
                                    cout << " Specificati animal sau scrieti 0 daca vreti sa va opriti din a enumera: ";
                                    cin >> anim;
                                    if(anim != "0"){
                                        animale.push_back(anim);
                                    }
                                    else if(anim == "0"){
                                        k13 = 0;
                                    }

                                }
                                ObCasa[modif_ob].setAnimale(animale);
                                break;


                            }

                            case 14:{
                                k_aux2 = 0;
                                break;
                            }

                            default:{
                                cout << "\n\tComanda Necunoscuta";
                            }

                        }







                    }


                }

                case 5:{
                    k_aux = 0;
                    break;
                }

                default:{
                    cout << "\n\tComanda Necunoscuta";
                }

            }

        }

    }
    else if(tip == "Bloc"){
        int contor = 0;
        int k_aux = 1;
        while (contor < n && k_aux == 1){
            int comanda;
            cout << "\n1-Citeste obiect;";
            cout << "\n2-Afiseaza Lista Obiecte;";
            cout << "\n3-Sterge Obiect";
            cout << "\n4-Modifica Obiect";
            cout << "\n5-STOP";

            cin >> comanda;

            switch (comanda) {
                case 1:{
                    Bloc o;
                    cin >> o;
                    ObBloc.push_back(o);
                    contor++;
                    break;
                }

                case 2:{
                    for(auto item = ObBloc.rbegin();item != ObBloc.rend();item++){
                        cout << *item << endl;
                    }
                    break;
                }
                case 3:{
                    if (contor == 0){
                        cout << "Din pacate nu exista obiecte create inca!" << endl;
                        break;
                    }
                    int ob_del;
                    cout << "Specificati numarul obiectului pe care doriti sa il stergeti: ";
                    cin >> ob_del;
                    if(ob_del > contor){
                        cout<<"Din pacate a-ti selectat un obiect care inca nu a fost creat!"<<endl;
                    }
                    ObBloc.erase(ObBloc.begin()+ob_del-1);
                    contor--;
                    break;

                }

                case 4:{
                    cout << "Specificati numarul obiectului pe care doriti sa il modificati: ";
                    int modif_ob;
                    cin >> modif_ob;
                    cout << "Specificati ce doriti sa modificati la acel obiect: " << endl;

                    int k_aux2 = 1;
                    while(k_aux2 == 1){
                        int modif;
                        cout << "\n1-Numarul de camere;";
                        cout << "\n2-Anul in care a fost construita cladirea;";
                        cout << "\n3-Numele locuitorului";
                        cout << "\n4-Daca plateste chirie sau nu[true/false]";
                        cout << "\n5-Cat plateste chirie lunar sau cat a platit pentru bloc";
                        cout << "\n6-Suprafata fiecarei camere a casei";
                        cout << "\n7-Orasul in care locuieste";
                        cout << "\n8-Strada pe care locuieste";
                        cout << "\n9-Numarul strazii pe care locuieste";
                        cout << "\n10-La ce etaj sa locuiasca";
                        cout << "\n11-Care sa fie numarul usii unde locuieste";
                        cout << "\n12-Care sa fie interfonul de la camera";
                        cout << "\n13-Nu mai doresc sa modific nimic!";

                        cin >> modif;

                        switch (modif) {
                            case 1:{
                                int nrCamere, aux3;
                                cout << "Specificati cate camere doriti sa aiba bloc: ";
                                cin >> nrCamere;
                                aux3 = ObBloc[modif_ob].getnrCamere();
                                ObBloc[modif_ob].setnrCamere(nrCamere);
                                if(nrCamere > aux3){
                                    cout << "A-ti adaugat " << nrCamere-aux3 << " camere in plus, deci trebuie specificate si suprafetele acestora!" << endl;
                                    vector<double> suprafata2;
                                    suprafata2 = ObBloc[modif_ob].getsuprafata();

                                    int i = 1;
                                    while(i<=nrCamere-aux3){
                                        cout << "Specificati suprafata camerei " << i << "nou adaugate: ";
                                        double sup_aux;
                                        cin >> sup_aux;
                                        suprafata2.push_back(sup_aux);
                                        i++;

                                    }
                                    ObBloc[modif_ob].setSuprafata(suprafata2);

                                }

                                else if(nrCamere < aux3){
                                    cout << "A-ti setat nr de camere ca fiind mai mic decat cel anterior , prin urmare trebuie sa specificati ce camere doriti sa stergeti"<<endl;
                                    cout << "Va trebui sa stergeti " << aux3 - nrCamere << " camere!" << endl;
                                    int aux4 = aux3 - nrCamere;
                                    while (aux4 != 0){
                                        cout << "Avem la dispozitie camerele: ";
                                        for(int i=1;i<=ObBloc[modif_ob].getnrCamere();i++){
                                            cout << i << ". cu suprafata: " << ObBloc[modif_ob].getsuprafata()[i] << endl;
                                        }
                                        cout << "Alegeti numarul camerei pe care doriti sa il stergeti: ";
                                        int nrCamera;
                                        double aux_it;
                                        cin >> nrCamera;
                                        vector<double> suprafata2;
                                        suprafata2 = ObBloc[modif_ob].getsuprafata();
                                        aux_it = suprafata2.begin()+nrCamera; ///


                                    }




                                }
                                break;

                            }

                            case 2:{
                                int an;
                                cout << "Specificati noul an: ";
                                cin >> an;
                                ObBloc[modif_ob].setAnCladire(an);
                                break;

                            }

                            case 3:{
                                string nume;
                                cout << "Dati noul nume al locuitorului: ";
                                cin >> nume;
                                ObBloc[modif_ob].setLocuitor(nume);
                                break;

                            }
                            case 4:{
                                bool chirie;
                                cout << "Specificati daca locuitorul sta cu chirie sau a cumparat bloc[true/false]." << endl;
                                cout << "Scrieti true daca vreti sa stea cu chirie sau nu in caz contrat(a cumparat bloc): ";
                                cin >> chirie;
                                ObBloc[modif_ob].setChirie(chirie);
                                break;

                            }
                            case 5:{
                                double chirie;
                                if (ObBloc[modif_ob].getChirie() == true){
                                    cout << "Specificati noua suma pe care doriti sa o plateasca lunar la chirie: ";
                                    cin >> chirie;
                                    ObBloc[modif_ob].setPret(chirie);
                                    break;

                                }
                                else{
                                    cout << "Specificati noua suma pe care doriti sa o fi platit proprietarul pentru bloc: ";
                                    cin >> chirie;
                                    ObBloc[modif_ob].setPret(chirie);
                                    break;

                                }

                            }
                            case 6:{
                                vector<double> suprafete;
                                int aux7;
                                aux7 = ObBloc[modif_ob].getsuprafata().size();
                                for(int i=1;i<=aux7;i++){
                                    double aux8;
                                    cout << "Specificati suprafata camereri " << i << " : ";
                                    cin >> aux8;
                                    suprafete.push_back(aux8);

                                }
                                ObBloc[modif_ob].setSuprafata(suprafete);
                                break;

                            }

                            case 7:{
                                cout << "Specificati orasul in care doriti sa locuiasca: ";
                                string oras;
                                cin >> oras;
                                ObBloc[modif_ob].setOrasAdresa(oras);
                                break;

                            }

                            case 8:{
                                cout << "Specificati Sstrada pe care doriti sa locuiasca: ";
                                string strada;
                                cin >> strada;
                                ObBloc[modif_ob].setStradaAdresa(strada);
                                break;

                            }
                            case 9:{
                                cout << "Specificati numarul strazii pe care doriti sa locuiasca: ";
                                int nr;
                                cin >> nr;
                                ObBloc[modif_ob].setnrStradaAdresa(nr);
                                break;

                            }

                            case 10:{
                                int etaj;
                                cout << "Specificati etajul la care doriti sa locuiasca: ";
                                cin >> etaj;
                                ObBloc[modif_ob].setEtaj(etaj);
                                break;


                            }
                            case 11:{
                                int numarUsa;
                                cout << "Specificati numarul usii la care doriti sa locuiasca: ";
                                cin >> numarUsa;
                                ObBloc[modif_ob].setNumarUsa(numarUsa);
                                break;

                            }
                            case 12:{
                                int nrInterfon;
                                cout << "Specificati numarul usii la care doriti sa locuiasca: ";


                            }
                            case 13:{
                                k_aux2 = 0;
                                break;


                            }
                            default:{
                                cout << "\n\tComanda Necunoscuta";
                            }


                        }







                    }


                }

                case 5:{
                    k_aux = 0;
                    break;
                }

                default:{
                    cout << "\n\tComanda Necunoscuta";
                }

            }

        }
        
        
    }



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