#include <iostream>
#include <vector>
#include "czas.h"
using namespace std;

class Obrabiarka  //klasa - definicja, opis
{
    private:
    vector < Czas > zbiorCzasow;                //zastosowanie vectora -> zdefiniowanie jego typu (klasy Czas)
    int IloscCzasow;                            //oraz jego nazwy i wielkosci "kontenera"

    public:
    //konstruktor
    Obrabiarka(int _ile);

    //konstruktor kopiujacy i operator przypisania zgodny z Etap 4 pkt 1
    Obrabiarka(const Obrabiarka& replika);

    void operator = (const Obrabiarka& replika)
    {
		this->zbiorCzasow = replika.zbiorCzasow;
	}
    //destruktor
    ~Obrabiarka();

    //funkcja dodawania czasu do listy
    void wrzuc_do_listy(Czas obx);

    //podglad
    void podgladacz();

    //wybrany czas z zestawienia
    void dokladny_podgladacz();

    //sumowanie obiektow klasy czas
    void zsumuj();

    //kopia „obrabiarki” zawieraj¹ca tylko pierwsze n czasów
    void kopia_n_czasow();

    //kopia "obrabiarki" zawierajace poczatkowe elementy, ktorych
    //suma miesci sie w zakresie podanym przez uzytkownika
    void stoper();
};
