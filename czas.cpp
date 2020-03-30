#include <iostream>
#include "czas.h"
#include <fstream>
#include <cstdlib>

using namespace std;

// Cialo funkcji konstruktora -> KONSTRUKTOR PRZECIAZONY
Czas::Czas(){
    godziny = 0;
    sekundy = 0;
    minuty = 0;
}
Czas::Czas(int g, int m, int s){
    godziny = g;
    sekundy = s;
    minuty = m;
    if(sekundy>=60)
    {
      minuty=minuty+(sekundy/60);
      sekundy=sekundy%60;
    }
    if(minuty>=60)
    {
        godziny=godziny+(minuty/60);
        minuty=minuty%60;
    }
}
Czas::Czas(int m, int s){
    godziny = 0;
    sekundy = s;
    minuty = m;
    if(sekundy>=60)
    {
      minuty=minuty+(sekundy/60);
      sekundy=sekundy%60;
    }
    if(minuty>=60)
    {
        godziny=godziny+(minuty/60);
        minuty=minuty%60;
    }
}
Czas::Czas(int s){
    godziny = 0;
    sekundy = s;
    minuty = 0;
    if(sekundy>=60)
    {
      minuty=minuty+(sekundy/60);
      sekundy=sekundy%60;
    }
    if(minuty>=60)
    {
        godziny=godziny+(minuty/60);
        minuty=minuty%60;
    }
}



//definicje ustawiania
void Czas::u_czasu(int g, int m, int s)
{
    if(g < 0 || m<0 || s<0)
	{
		std::cout << "Nie mozna wprowadzic ujemnego czasu" << std::endl;
		return;
	}


    godziny=g;
    minuty=m;
    sekundy=s;
    if(sekundy>=60)
    {
      minuty=minuty+(sekundy/60);
      sekundy=sekundy%60;
    }
    if(minuty>=60)
    {
        godziny=godziny+(minuty/60);
        minuty=minuty%60;
    }

}

void Czas::u_czasu(int m, int s)
{
    minuty=m;
    sekundy=s;
     if(sekundy>=60)
    {
      minuty=minuty+(sekundy/60);
      sekundy=sekundy%60;
    }
    if(minuty>=60)
    {
        godziny=godziny+(minuty/60);
        minuty=minuty%60;
    }

}

void Czas::u_czasu(int s)
{
    sekundy=s;
    if(sekundy>=60)
    {
      minuty=minuty+(sekundy/60);
      sekundy=sekundy%60;
    }
    if(minuty>=60)
    {
        godziny=godziny+(minuty/60);
        minuty=minuty%60;
    }
}

//definicje zwracania
int Czas::zwroc_godziny()
{
    return godziny;
}

int Czas::zwroc_minuty()
{
    return minuty;
}
 int Czas::zwroc_sekundy()
 {
     return sekundy;
 }

//definicja wyswietlania
void Czas::wyswietl()
{
    cout << "Godziny: " << godziny << " Minuty: " << minuty << " Sekundy: " << sekundy <<endl;

}





