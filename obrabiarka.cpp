#include <iostream>
#include "obrabiarka.h"
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
//konstruktor
Obrabiarka::Obrabiarka(int _ile)
{
    IloscCzasow=_ile;
    zbiorCzasow.resize(_ile);
}
//konstruktor kopiujacy
Obrabiarka::Obrabiarka(const Obrabiarka& replika)
{
    this->zbiorCzasow = replika.zbiorCzasow;
}
//destruktor
Obrabiarka::~Obrabiarka()
{
	zbiorCzasow.clear();
}

//cialo funkcji dodawania czasu do listy

void Obrabiarka::wrzuc_do_listy(Czas obx)
{
    zbiorCzasow.push_back(obx);
}


//cialo wyswietlania zawartosci obiektu klasy obrabiarka

void Obrabiarka::podgladacz()
{
    cout << "\nWyswietlam wszystkie elementy listy:"<<endl;
    for(auto& gaz : zbiorCzasow)
	{
		gaz.wyswietl();
	}

}

// cialo wyswietlania zawartosci pojedynczego obiektu klasy Czas zawartego w obiekcie klasy Obrabiarka
void Obrabiarka::dokladny_podgladacz()
{
    cout << "Na liscie jest " <<zbiorCzasow.size()<<" elementow"<<endl;
    int w;
    cout << "Ktory czas chcesz podejrzec?" << endl;
    cin >> w;
    w=w-1;
    if(w>=zbiorCzasow.size()||w<0)
    {
        cout << "Wybrales numer spoza listy"<<endl;
    }
    else
    {
    zbiorCzasow[w].wyswietl();
    }

}

void Obrabiarka::zsumuj()
{


    Czas rezultat;

	for(auto& gaz: zbiorCzasow)
	{
		rezultat =rezultat + gaz;
	}

    cout <<"Laczny czas wynosi:\n";
    rezultat.wyswietl();



}


Czas Obrabiarka::plusik(int _ile)
{


    Czas rezultat;
    for (int i=0;i<_ile;i++)

{

    rezultat =rezultat + zbiorCzasow[i];

    return rezultat;
}
  //  cout <<"Laczny czas wynosi:\n";
  //  rezultat.wyswietl();
}



//cialo funkcji kopii pewnej ilosci elementow
Obrabiarka Obrabiarka::kopia_n_czasow()
{
    cout << "\nWyswietlam liste skopiowanych czasow:"<<endl;
    int n;
    cout << "\nPodaj ile poczatkowych czasow chcesz skopiowac:" << endl;
    cin >> n;

    Obrabiarka kopia();

   for ( int i = 0; i < kopia.size(); i++)
 {
    kopia.assign(zbiorCzasow.begin(),zbiorCzasow.begin()+n);
  /*   cout <<"Nr." << i+1<<" ";
     kopia[i].wyswietl(); */

 }
 }

    return kopia;
 }


//cia³o stopera
void Obrabiarka::stoper()
{

Czas zegarek;
Obrabiarka replika();

    int g,m,s,i;
    cout << "\nPodaj czas \n";
    cout << "Ustaw ilosc godzin \n"; cin >> g;
    cout << "Ustaw ilosc minut \n"; cin >> m;
    cout << "Ustaw ilosc sekund \n"; cin >> s;

    zegarek.u_czasu(g,m,s);
    zegarek.wyswietl();


    for (i=0; replika.plusik()<zegarek) && (i<zbiorCzasow.size();i++)
    {
        replika.push_back(zbiorCzasow.at(i));
    }
    if (z<replika.plusik())
    {
        replika.pop_back();
    }
}



