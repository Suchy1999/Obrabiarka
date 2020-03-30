#include <iostream>
#pragma once
using namespace std;

class Czas                                                  //klasa - definicja, opis
{
private:
int godziny;
int minuty;
int sekundy;
public:
//konstruktor
Czas();
Czas(int g, int m, int s);
Czas(int m, int s);
Czas(int s);
//destruktor
// Nie ma potrzeby istnienia destruktora w naszej klasie Czas.
// Nasza klasa Czas nie alokuje w zaden sposob pamieci dynamicznej, nie ma koniecznosci zapisania raportu z istnienia obiektu itd.
// nie ma koniecznosci zapisania raportu z istnienia obiektu itd.


//ustawianie
void u_czasu(int godziny, int minuty, int sekundy);
void u_czasu(int minuty, int sekundy);
void u_czasu(int sekundy);

//zwracanie
int zwroc_godziny();
int zwroc_minuty();
int zwroc_sekundy();

//wyswietlanie
void wyswietl();



//PRZECIAZANIE OPERATORA +:

//dodawanie czasu do istniejacego obiektu
Czas operator+ (int s)
{
	Czas wynik;
	int zapas1,zapas2;

	wynik.sekundy = sekundy + s;
	zapas1=wynik.sekundy/60;
	wynik.sekundy=wynik.sekundy%60;
	wynik.minuty= minuty+zapas1;
	zapas2=wynik.minuty/60;
    wynik.minuty=wynik.minuty%60;
	wynik.godziny=godziny+zapas2;
	return wynik;
}


// dodawanie dwoch czasow
Czas operator+ (Czas obj)
{

    Czas suma = Czas();

    suma.sekundy =this -> sekundy + obj.zwroc_sekundy();

    //zabezpieczenie: gdy czas przekroczy 60 s ->staje sie 1 minuta
        int zapas1,zapas2;
        zapas1=suma.sekundy/60;
        zapas2=this->minuty+obj.zwroc_minuty();
        suma.minuty=this-> minuty + obj.zwroc_minuty();
        suma.minuty=zapas2+zapas1;
        suma.sekundy=suma.sekundy%60;

//zabezpieczenie: gdy czas przekroczy 60 minut ->staje sie 1 godzina
        int zapas3,zapas4;
        zapas3=suma.minuty/60;
        zapas4=this->godziny+obj.zwroc_godziny();
        suma.godziny =this -> godziny + obj.zwroc_godziny();
        suma.godziny=zapas3+zapas4;
        suma.minuty=suma.minuty%60;

        return suma;
}

//USTAWIANIE OPERATOROW POROWNAWCZYCH:
bool operator ==(Czas obj)
{
    if(this->sekundy==obj.sekundy && this -> minuty==obj.minuty && godziny==obj.godziny)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator > (Czas obj)
{
    if (this->godziny>obj.godziny)
    {
        return true;
    }
    else
    {
        if (this ->minuty>obj.minuty)
        {
            return true;
        }
        else
        {
            if(this->sekundy>obj.sekundy)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool operator < (Czas obj)
{
    if (this->godziny<obj.godziny)
    {
        return true;
    }
    else
    {
        if (this ->godziny>obj.godziny)
        {
            return false;
        }
        else
        {
            if(this->minuty<obj.minuty)
            {
                return true;
            }
            else
            {
                if(this->minuty>obj.minuty)
                {
                    return false;
                }
                else
                {
                    if(this->sekundy<obj.sekundy)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
}

void operator =(Czas obj)
{

    this->sekundy = obj.sekundy;
    this->minuty = obj.minuty;
    this->godziny = obj.godziny;
 }

};

