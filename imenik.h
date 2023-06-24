#ifndef IMENIK_H
#define IMENIK_H
#include "kontakt.h"
#include <string>
#include<vector>
using namespace std ;

class Imenik{
    struct Cvor {
        Cvor *prethodni, *sljedeci;
        Kontakt k ;
        Cvor(Cvor *pr=nullptr, Cvor *slj=nullptr) : prethodni(pr), sljedeci(slj) {} ;
        Cvor(Cvor *pr,Cvor *slj, string n, string m, string f) : prethodni(pr),sljedeci(slj), k(Kontakt(n,m,f)) {}
    };
    public:
    string naziv_imenika;
    int broj_kontakata;
    Cvor *head;
    Cvor *tail;
    Imenik(string ime);
    Imenik(const Imenik &kopija);
    Imenik(Imenik && kopija) ;
    Imenik& operator = (const Imenik& rhs) ;
    Imenik& operator = (Imenik && rhs) ;
    ~Imenik(){ Ocisti_Imenik(); delete head; delete tail; }
    Imenik (vector <Kontakt> v) ;
    void DodajNaKraj(Kontakt k) ;
    void DodajNaPocetak(Kontakt k) ;
    void DodajKontakt(Kontakt k) ;
    void Ispisi_Imenik();
    void Obrisi_Kontakt(Kontakt k);
    void PromijeniNazivKontakta(Kontakt &k1, string ime) ;
    void PromijeniMobilni(Kontakt &k1,string mob) ;
    void PromijeniFiksni(Kontakt &k1,string fix) ;
    void Sortiraj(Imenik &imenik,Cvor *head,Cvor *tail,int n) ;
    void PretraziPoNazivu (string s) ;
    void PretraziPoBroju (string s) ;
    void Ocisti_Imenik();
    void Spoji(Imenik& imenik1,Imenik& imenik2) ;
    void Obrisi_Duplikate() ;
    bool DaLiSuJednaki(const Kontakt& k1,const Kontakt& k2);
};
//#include "imenik.cpp"
#endif
