#pragma once
#include "Stale.h"
#include "obj_fiz.h"
#include "planeta_Newton_prosty.h"
#include <vector>
#include "warunki_stop.h"
#include "SFML\System.hpp"
using namespace std;
class Symulacja
{
public:
	//Symulacja() : zegar_sym(sf::Time::Zero), krok(sf::seconds(60)) {}
	Symulacja() : zegar_sym(sf::Time::Zero), krok(sf::seconds(60)) {}
	void dodaj_obj(obj_fiz* obj)
	{
		obiekty.push_back(obj);
	}
	void symuluj(); 
	//dodaj warunek stop
	//usun warunek stop
	//ustal typ symulacji
	//symuluj, krok czasowy
	//zmien typ symulacji
	//wyswietl
	~Symulacja();
private:
	//srodowisko
	//vector obiektow fizycznych
	Srodowisko obszar;
	vector<obj_fiz*> obiekty;
	sf::Time zegar_sym;
	sf::Time krok;
};

