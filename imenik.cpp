#ifndef imenik_cpp
#define imenik_cpp
#include "imenik.h"
#include <iostream>
using namespace std;

Imenik :: Imenik(string ime){
   head=new Cvor;
   tail=new Cvor(head);
   head->sljedeci=tail;
   naziv_imenika=ime;
   broj_kontakata=0;
}
Imenik :: Imenik(const Imenik &kopija){
    head=new Cvor();
    tail=new Cvor(head);
    head->sljedeci=tail;
    naziv_imenika=kopija.naziv_imenika;
    Cvor *trenutni = kopija.head->sljedeci;
    broj_kontakata=0;
    while(trenutni->sljedeci!=nullptr){
        DodajNaKraj(trenutni->k);
        trenutni=trenutni->sljedeci;
        }
}
Imenik :: Imenik(Imenik && kopija){
    head=kopija.head;
    tail=kopija.tail;
    broj_kontakata=kopija.broj_kontakata;
    naziv_imenika=kopija.naziv_imenika;
    kopija.head=nullptr;
    kopija.tail=nullptr;
    kopija.broj_kontakata=0;
    kopija.naziv_imenika="" ;
}
Imenik& Imenik :: operator = (const Imenik& rhs){
      Ocisti_Imenik();
      naziv_imenika=rhs.naziv_imenika;
      Cvor *trenutni=rhs.head->sljedeci;
      for (int i=0; i<rhs.broj_kontakata; i++){
            DodajNaKraj(trenutni->k);
            trenutni=trenutni->sljedeci;
      }
     return *this;
}
Imenik& Imenik :: operator = (Imenik &&rhs){
        Ocisti_Imenik();
        delete head;
        delete tail;
        head=rhs.head;
        tail=rhs.tail;
        naziv_imenika=rhs.naziv_imenika;
        broj_kontakata=rhs.broj_kontakata;
        rhs.head=nullptr;
        rhs.tail=nullptr;
        rhs.naziv_imenika="" ;
        rhs.broj_kontakata=0;
        return *this;
}
void Imenik :: DodajKontakt(Kontakt k){
     Cvor *novi=new Cvor(nullptr,nullptr,k.ime_kontakta,k.mobilni,k.fiksni);
     Cvor *trenutni1=head->sljedeci;
     while(trenutni1!=nullptr) {
         if(trenutni1->k.ime_kontakta==k.ime_kontakta)
              throw "Kontakt s ovim imenom vec postoji";
         trenutni1=trenutni1->sljedeci;
     }
    bool dodan=false;
    if(broj_kontakata==0){
         DodajNaPocetak(novi->k);
          dodan=true ;}
     else {
        Cvor *trenutni=head->sljedeci;
        while(trenutni!=nullptr){
          if(novi->k.ime_kontakta < trenutni->k.ime_kontakta){
              trenutni->prethodni->sljedeci=novi;
              novi->sljedeci=trenutni;
              novi->prethodni=trenutni->prethodni;
              trenutni->prethodni=novi;
              dodan=true;
              broj_kontakata++;
              break; }
          trenutni=trenutni->sljedeci;
        }
     }
     if (dodan==false) {
         DodajNaKraj(k);
     }
}
void Imenik :: Ispisi_Imenik(){
   cout << naziv_imenika << endl ;
   Cvor *trenutni=head->sljedeci;
   while(trenutni->sljedeci!=nullptr){
      cout << trenutni->k.ime_kontakta << " " << trenutni->k.mobilni << " " << trenutni->k.fiksni <<endl;
      trenutni=trenutni->sljedeci;
    }
}
void Imenik :: Obrisi_Kontakt(Kontakt k){
     Cvor *trenutni=head->sljedeci;
     while (trenutni->k.ime_kontakta != k.ime_kontakta)
           trenutni=trenutni->sljedeci;
    trenutni->prethodni->sljedeci=trenutni->sljedeci;
    trenutni->sljedeci->prethodni=trenutni->prethodni;
    delete trenutni;
    broj_kontakata--;
}
void Imenik :: Ocisti_Imenik(){
    while(broj_kontakata!=0){
       Obrisi_Kontakt(head->sljedeci->k);
    }
}
void Imenik :: PromijeniNazivKontakta(Kontakt &k1,string ime){
    Cvor *trenutni = head->sljedeci;
    while (trenutni!=nullptr) {
          if(trenutni->k.ime_kontakta==k1.ime_kontakta){
              k1.ime_kontakta=ime;
              trenutni->k.ime_kontakta=ime;}
          trenutni=trenutni->sljedeci;
    }
}

void Imenik :: PromijeniMobilni(Kontakt &k1,string mob){
    Cvor *trenutni = head->sljedeci;
    while (trenutni!=nullptr) {
          if(trenutni->k.ime_kontakta==k1.ime_kontakta){
              k1.mobilni=mob;
              trenutni->k.mobilni=mob;}
          trenutni=trenutni->sljedeci;
    }
}
void Imenik :: PromijeniFiksni(Kontakt &k1,string fiksni){
    Cvor *trenutni = head->sljedeci;
    while (trenutni!=nullptr) {
          if(trenutni->k.ime_kontakta==k1.ime_kontakta){
              k1.fiksni=fiksni;
              trenutni->k.fiksni=fiksni;}
          trenutni=trenutni->sljedeci;
     }
}

void Imenik :: PretraziPoNazivu(string s){
    Cvor *trenutni=head->sljedeci;
    while(trenutni !=nullptr){
        string ime ;
        string rijec;
        for(int i=0; i<trenutni->k.ime_kontakta.length(); i++)
             ime+=tolower(trenutni->k.ime_kontakta[i]) ;
        for(int i=0; i<s.length(); i++)
             rijec+=tolower(s[i]);
        if(ime.find(rijec,0) != string::npos)
           cout << trenutni->k.ime_kontakta <<" " << trenutni->k.mobilni << " " << trenutni->k.fiksni << endl;
        trenutni=trenutni->sljedeci;
    }
}
void Imenik :: PretraziPoBroju (string s){
    Cvor *trenutni=head->sljedeci;
    while(trenutni !=nullptr){
        bool dobar=true;
        for(int i=0; i<s.length();i++)
            if(trenutni->k.fiksni[i]!=s[i]){
               dobar=false;
               break;
               }
        if(dobar==false) {
           dobar=true;
           for(int i=0; i<s.length();i++)
              if(trenutni->k.mobilni[i]!=s[i]){
                 dobar=false;
                 break;
               }}
        if (dobar)
           cout << trenutni->k.ime_kontakta << " " << trenutni->k.mobilni <<" " << trenutni->k.fiksni << endl; ;
        trenutni=trenutni->sljedeci;
    }
}
void Imenik :: DodajNaKraj(Kontakt k){
     Cvor *novi=new Cvor(tail->prethodni,tail,k.ime_kontakta,k.mobilni,k.fiksni);
     tail->prethodni=novi;
     novi->prethodni->sljedeci=novi ;
     broj_kontakata++;
}
void Imenik :: DodajNaPocetak (Kontakt k){
     Cvor *novi=new Cvor(head,head->sljedeci,k.ime_kontakta,k.mobilni,k.fiksni);
     head->sljedeci=novi;
     novi->sljedeci->prethodni=novi;
     broj_kontakata++;
}

Imenik :: Imenik(vector<Kontakt> v){
    Imenik novi("Novi") ;
    for (int i=0; i<v.size(); i++){
        novi.DodajNaKraj(v[i]); }
    novi.broj_kontakata=v.size();
    int n=v.size();
    //Sortiraj(novi,novi.head->sljedeci,novi.tail,n);
    head=novi.head;
    tail=novi.tail;
    naziv_imenika=novi.naziv_imenika;
}
/*void Imenik :: Sortiraj(Imenik &imenik,Cvor *head,Cvor *tail,int br){
   if(br == 1 )
          return ;
    Cvor *sredina=head;
    for(int i=0; i<br/2; i++)
        sredina=sredina->sljedeci;
    //cout <<"Sredina je " << sredina->k.naziv_kontakta <<endl ;

    br=br/2;
    Sortiraj(imenik,head,sredina,br) ;
    Sortiraj(imenik,sredina,tail,br) ;

    Imenik sortirani("S")  ;

    Cvor *lp=head;

    Cvor *dp=sredina;
   // cout <<"Pocetak je " << lp->k.naziv_kontakta <<", a kraj je " << dp->k.naziv_kontakta << endl;
    while(lp != sredina && dp!=tail){
        //cout << "Poredim " << lp->k.naziv_kontakta <<" i " << dp->k.naziv_kontakta <<endl ;
        if(lp->k.naziv_kontakta < dp->k.naziv_kontakta){
            sortirani.Push_Back(lp->k) ;
          //  cout <<"dodala sam " << lp->k.naziv_kontakta << endl;
            lp=lp->sljedeci;}
        else {
             sortirani.Push_Back(dp->k);
            // cout <<"dodala sam " << dp->k.naziv_kontakta << endl;
             dp=dp->sljedeci;
        }
    }
    if(dp == tail)
       while(lp!=sredina){
          sortirani.Push_Back(lp->k);
          cout<<"Dodala sam " << lp->k.naziv_kontakta<< endl ;
          lp=lp->sljedeci;
        }
    else {
        while(dp!=tail) {
            sortirani.Push_Back(dp->k);
            cout<<"Dodala sam " << dp->k.naziv_kontakta<< endl ;
            dp=dp->sljedeci;
    }}
    sortirani.Ispisi_Imenik();
    //cout<<endl;
   /* Cvor *trenutni=sortirani.head->sljedeci;
    while(trenutni->sljedeci!=nullptr){
       head=trenutni;
       head=head->sljedeci;
       trenutni=trenutni->sljedeci;
    }
}
void Imenik :: Obrisi_Duplikate(){
     Cvor *trenutni=head->sljedeci;
     while(trenutni!=nullptr){
          cout << trenutni->k.naziv_kontakta <<endl ;
          trenutni=trenutni->sljedeci;
     }
}*/
bool Imenik :: DaLiSuJednaki(const Kontakt& k1,const Kontakt& k2){
    return(k1.ime_kontakta==k2.ime_kontakta && k1.mobilni==k2.mobilni && k1.fiksni== k2.fiksni);
}

void Imenik :: Spoji(Imenik& imenik1,Imenik& imenik2){
     Imenik novi("Imenik");
     Cvor *trenutni1=imenik1.head->sljedeci;
     Cvor *trenutni2=imenik2.head->sljedeci;
     while(trenutni1->sljedeci!=nullptr && trenutni2->sljedeci!=nullptr){
        if(DaLiSuJednaki(trenutni1->k, trenutni2->k)){
              novi.DodajNaKraj(trenutni1->k);
              trenutni1=trenutni1->sljedeci;
              trenutni2=trenutni2->sljedeci;}

        else if (trenutni1->k.ime_kontakta < trenutni2->k.ime_kontakta){
              novi.DodajNaKraj(trenutni1->k);
              trenutni1=trenutni1->sljedeci;}

        else if(trenutni1->k.ime_kontakta==trenutni2->k.ime_kontakta && trenutni1->k.fiksni == trenutni2->k.fiksni
                 && trenutni1->k.mobilni =="" && trenutni2->k.mobilni!="") {
                        novi.DodajNaKraj(trenutni2->k);
                        trenutni1=trenutni1->sljedeci;
                        trenutni2=trenutni2->sljedeci;}

        else if(trenutni1->k.ime_kontakta==trenutni2->k.ime_kontakta && trenutni1->k.fiksni == trenutni2->k.fiksni
                 && trenutni1->k.mobilni != "" && trenutni2->k.mobilni==""){
                        novi.DodajNaKraj(trenutni1->k);
                        trenutni1=trenutni1->sljedeci;
                        trenutni2=trenutni2->sljedeci;}

        else if(trenutni1->k.ime_kontakta==trenutni2->k.ime_kontakta && trenutni1->k.mobilni == trenutni2->k.mobilni
                 && trenutni1->k.fiksni =="" && trenutni2->k.fiksni!="") {
                        novi.DodajNaKraj(trenutni2->k);
                        trenutni1=trenutni1->sljedeci;
                        trenutni2=trenutni2->sljedeci;}

        else if(trenutni1->k.ime_kontakta==trenutni2->k.ime_kontakta && trenutni1->k.mobilni == trenutni2->k.mobilni
                 && trenutni1->k.fiksni != "" && trenutni2->k.fiksni==""){
                        novi.DodajNaKraj(trenutni1->k);
                        trenutni1=trenutni1->sljedeci;
                        trenutni2=trenutni2->sljedeci;}

         else if (trenutni1->k.ime_kontakta==trenutni2->k.ime_kontakta && trenutni1->k.mobilni != trenutni2->k.mobilni){
              trenutni1->k.ime_kontakta=trenutni1->k.ime_kontakta + "-" + imenik1.naziv_imenika;
              trenutni2->k.ime_kontakta=trenutni2->k.ime_kontakta + "-" + imenik2.naziv_imenika;
              novi.DodajNaKraj(trenutni1->k);
              novi.DodajNaKraj(trenutni2->k);
              trenutni1=trenutni1->sljedeci;
              trenutni2=trenutni2->sljedeci; }

         else if (trenutni1->k.ime_kontakta==trenutni2->k.ime_kontakta && trenutni1->k.fiksni != trenutni2->k.fiksni){
              trenutni1->k.ime_kontakta=trenutni1->k.ime_kontakta + "-" + imenik1.naziv_imenika;
              trenutni2->k.ime_kontakta=trenutni2->k.ime_kontakta + "-" + imenik2.naziv_imenika;
              novi.DodajNaKraj(trenutni1->k);
              novi.DodajNaKraj(trenutni2->k);
              trenutni1=trenutni1->sljedeci;
              trenutni2=trenutni2->sljedeci;}

         else {
              novi.DodajNaKraj(trenutni2->k);
              trenutni2=trenutni2->sljedeci; }
      }
      if(trenutni1->sljedeci==nullptr)
          while(trenutni2->sljedeci!=nullptr){
             novi.DodajNaKraj(trenutni2->k);
             trenutni2=trenutni2->sljedeci;}
      else {
          while(trenutni1->sljedeci!=nullptr){
             novi.DodajNaKraj(trenutni1->k);
             trenutni1=trenutni1->sljedeci;}
           }
      Cvor *trenutni=novi.head->sljedeci ;
      while(trenutni->sljedeci!=nullptr){
            DodajNaKraj(trenutni->k);
            trenutni=trenutni->sljedeci; }
}

#endif
