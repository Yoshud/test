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
	Symulacja() : zegar_sym(sf::Time::Zero), krok(sf::seconds(60)) {}
	void dodaj_obj(obj_fiz* obj)
	{
		obiekty.push_back(obj);
	}
	void symuluj(); 
	void dodaj_warunek_stop(warunek_stop_unique* warunek) { warunki_stopu.dodaj_warunek_stop(warunek); } //wywoluje siê konstrukcj¹:  new <nazwa klasy warunku stop>(<parametry wywolania warunku>) np. new limit_czasu(sf::hour = 24) 
	void usun_warunek(string alias) { warunki_stopu.usun_warunek_stop(alias); } //wywoluje sie podajac jako alias nazwe warunku - analogicznie do python (chyba ze podczas definiowania wlasnego warunku uzna sie inaczej)
	void ustaw_krok_czasowy(const sf::Time& nowy_krok) { krok = nowy_krok; }
	//ustal typ symulacji
	//zmien typ symulacji
	~Symulacja();
private:

	warunki_stop warunki_stopu;
	Srodowisko obszar;
	vector<obj_fiz*> obiekty;
	sf::Time zegar_sym;
	sf::Time krok;
};

