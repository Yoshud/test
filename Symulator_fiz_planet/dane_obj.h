#pragma once
#include "wektor_2D.h"
#include "SFML/System.hpp"
#include "punkt_materialny_pomocniczy.h"

class dane_obj
{
public:
	dane_obj();
	~dane_obj();
//private:
	wektor_2D<double> srodek_masy; 
	double masa;
	double moment_pedu;
	zbior_punktow_materialnych_pomocniczy* opisujace_punkty; //wskaznik prawdopodobnie nie jest potrzebny i wystarczylby operator przenoszoacy dla zachowania predkosci
	sf::Time czas; 

	punkt_materialny_pomocniczy operator[] (int i)
	{
		return opisujace_punkty->punkty_materialne[i];
	}
};

