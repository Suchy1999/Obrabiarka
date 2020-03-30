#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include "czas.h"
#include "obrabiarka.h"





int main()
{
cout << "Czas pierwszy wynosi: ";
Czas obiekt1 (1,2,8);
cout << "Czas drugi wynosi: ";
Czas obiekt2 (150);
obiekt1.wyswietl();
obiekt2.wyswietl();
cout << "Porownanie czasow: "<< endl;
if (obiekt1==obiekt2)
{
    cout << "Czasy sa rowne" << endl;
}
else
{
    cout << "Czasy nie sa rowne" << endl;
    if(obiekt1<obiekt2)
    {
        cout << "Czas pierwszy jest mniejszy" << endl;
    }
    else
    {
        cout << "Czas drugi jest mniejszy" << endl;
    }
}



int s=4000;
//obiekt3=obiekt1+s;
cout << "Czas pierwszy po dodaniu "<<s<<"s wynosi: ";
(obiekt1+s).wyswietl();
cout <<"Suma obu czasow daje nam: ";
(obiekt1 + obiekt2).wyswietl();

Czas obiekt3(1,2,30);
Czas obiekt4(45,0);
cout << "\n\nDodaje do obrabiarki liste czasow:"<<endl;
Obrabiarka lista(0);
lista.wrzuc_do_listy(obiekt1);
lista.wrzuc_do_listy(obiekt2);
lista.wrzuc_do_listy(obiekt3);
lista.wrzuc_do_listy(obiekt4);
lista.zsumuj();
//lista.dokladny_podgladacz();
lista.podgladacz();

char numer;
cout <<"\nW jaki sposob chcesz skopiowac czasy?"<<endl;
cout <<"1.Kopiowanie n pierwszych czasow"<<endl;
cout <<"2.Kopiowanie pierwszych czasow nie przekraczajacych \nzakresu czasowego podanego przez uzytkownika"<<endl;
cin >>numer;
switch(numer)
{

case '1':

lista.kopia_n_czasow();

break;

case '2':

lista.stoper();

break;

default: cout << "Zly wybor!" << endl;

}
}

