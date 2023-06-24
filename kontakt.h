#ifndef KONTAKT_H
#define KONTAKT_H
#include "imenik.h" ;
#include<iostream>
#include<string>

using namespace std;

struct Kontakt {
        string ime_kontakta;
        string mobilni;
        string fiksni;
        void Provjera(string n, string m, string f){
            if (n == "")
               throw "Neophodan je naziv kontakta." ;
           else if(m=="" && f=="")
               throw"Neophodan je mobilni ili fiksni broj kontakta." ;
          else {
               for (int i=0; i<m.length(); i++)
                   if (!isdigit(m[i]))
                      throw "Mobilni broj mora sadrzavati samo cifre.";
               for (int i=0; i<f.length(); i++)
                   if (!isdigit(f[i]))
                      throw"Fiksni broj mora sadrzavati samo cifre.";
        }
        }
        Kontakt() : ime_kontakta(""), mobilni(""), fiksni(""){}
        Kontakt(string n, string m, string f){
               Provjera(n,m,f) ;
               ime_kontakta=n;
               mobilni=m;
               fiksni=f;
        }
};

#endif
