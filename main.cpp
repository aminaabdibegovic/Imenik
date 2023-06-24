#include<iostream>
#include<string>
#include<vector>
#include "imenik.h"
using namespace std ;

int main(){
    try{
    Imenik imenik1("PMF-osoblje");
    Kontakt k1("Irma","061216312","");
    Kontakt k2("Irma","062145365","");
    Kontakt k3("Adna","","030257854");
    Kontakt k4("Mersiha","","030272555");
    Kontakt k5("Adnana","062145365","030271169");
    Kontakt k6("Adnana","062145365","");
    Kontakt k7("Vildana","062016302","");
    Kontakt k8("Sara","061015303","");
    Kontakt k9("Tarik","062016302","271169");
    Kontakt k10("Tarik","","271169");
    Kontakt k11("Selma","","271177");
    Kontakt k12("Selma","","271177");
    Kontakt k13("Eldar","061494787","222487");
    Kontakt k14("Amar","06145887","272477");
    imenik1.DodajKontakt(k1) ;
    imenik1.DodajKontakt(k3) ;
    imenik1.DodajKontakt(k5) ;
    imenik1.DodajKontakt(k7) ;
    imenik1.DodajKontakt(k11) ;
    imenik1.DodajKontakt(k9) ;
    imenik1.DodajKontakt(k13) ;
    imenik1.Ispisi_Imenik();

    Imenik imenik2("PMF-studenti") ;
    imenik2.DodajKontakt(k4);
    imenik2.DodajKontakt(k8);
    imenik2.DodajKontakt(k14) ;
    imenik2.DodajKontakt(k2);
    imenik2.DodajKontakt(k10);
    imenik2.DodajKontakt(k6) ;
    imenik2.DodajKontakt(k12) ;
    imenik2.Ispisi_Imenik();

    Imenik imenik3("PMF") ;
    imenik3.Spoji(imenik1,imenik2);
    imenik3.Ispisi_Imenik();
    imenik3.Obrisi_Kontakt(k10);
    cout << endl ;
    imenik3.PretraziPoNazivu("ANA");
    cout <<endl;
    imenik3.PretraziPoBroju("061");
    cout <<endl;
    imenik3.Ispisi_Imenik();

    imenik3.PromijeniNazivKontakta(k13,"Amar");
    imenik3.PromijeniFiksni(k5,"030271244");
    imenik3.Ispisi_Imenik();

    imenik3 = imenik1 ;
    imenik3.Ispisi_Imenik();
    cout << endl;
    Imenik imenik4= move(imenik2);
    imenik4.Ispisi_Imenik();
    imenik4.Ocisti_Imenik();
    cout<<endl;
    Imenik imenik5(imenik3) ;
    imenik5.Ispisi_Imenik();

    }
  catch(const char poruka []) {
    cout << poruka;
}
}

